#include "../../libs/cSpec/export/cSpec.h"
#include "../../src/string_base/string_base.h"

static void _external_string_add(char *str, const char *value) {
  string_add(str, value);
}

static void _external_vector_add_string2(char ***v, const char *value) {
  vector_add(*v, (char *)value);
}

static void _external_vector_add_string(char ***v, char *value) {
  string_add(value, "sth else");
  _external_vector_add_string2(v, value);
}

static void _external_vector_add_int(int **v, int value) {
  vector_add(*v, value);
}

module(T_string_base, {
  describe("string", {
    it("creates a new empty string", {
      char *str = string_new("");
      assert_that(str isnot NULL);
      assert_that(string_equals(str, ""));
    });

    it("creates a new non-empty string", {
      char *str = string_new("anything");
      assert_that(str isnot NULL);
    });

    it("creates a string with an initial char*", {
      char *str = string_new("initial");
      assert_that(str isnot NULL);
    });

    context("when a string pointer is not NULL", {
      it("returns the char* when calling `string_get`", {
        char *str = string_new("initial");
        assert_that(sizeof(str) is sizeof(char *));
      });
    });

    context("when the initial value exitsts", {
      it("returns the correct char* when calling `string_get`", {
        char *str = string_new("initial");
        assert_that_charptr(str equals to "initial");
      });
    });

    it("removes underscores from strings", {
      char *test = string_new("a_word_with_underscores");
      test = string_remove_underscores(test);
      assert_that_charptr(test equals to "awordwithunderscores");

      test = string_new("42_000_000");
      test = string_remove_underscores(test);
      assert_that_charptr(test equals to "42000000");
    });

    context("on external function string manipulation", {
      it("adds a string that has been initialized", {
        char *test = string_new("initial");
        _external_string_add(test, " - test");
        assert_that_charptr(test equals to "initial - test");
      });

      it("adds a string that has NOT been initialized", {
        char *test = string_new("");
        _external_string_add(test, "this is an initial string");
        assert_that_charptr(test equals to "this is an initial string");
      });

      it("adds a string in a vector of strings in an extenral function", {
        char **v = vector_string_new("one");
        assert_that(vector_size(v) is 1);
        assert_that_charptr(v[0] equals to "one");
        char *two = string_new("two");
        char *three = string_new("three");
        _external_vector_add_string(&v, two);
        _external_vector_add_string(&v, three);
        assert_that_int(vector_size(v) equals to 3);
        assert_that_charptr(v[1] equals to "twosth else");
        assert_that_charptr(v[2] equals to "threesth else");
      });

      it("adds numbers in a vector of numbers in an extenral function", {
        int *v = NULL;
        assert_that(vector_size(v) is 0);
        for (int i = 0; i < 20; i++) {
          _external_vector_add_int(&v, i);
        }

        for (int i = 0; i < 20; i++) {
          assert_that_int(v[i] equals to i);
        }

        assert_that_int(vector_size(v) equals to 20);
      });
    });
  });
})
