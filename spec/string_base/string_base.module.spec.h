#include "../../libs/cSpec/export/cSpec.h"
#include "../../src/string_base/string_base.h"
#include "../../src/string_substring/string_substring.h"

static void _external_string_add(char **str, const char *value) {
  string_add(*str, value);
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
    it("initializes a null string", {
      char *str = NULL;
      assert_that(str is NULL);
      string_add(str, "test");
      assert_that(str isnot NULL);
      assert_that_charptr(str equals to "test");
    });

    context("on initializing a string", {
      it("creates a new empty string", {
        char *str = string_new("");
        assert_that(str isnot NULL);
        assert_that(string_equals(str, string_new("")));
      });

      it("creates a new non-empty string", {
        char *str = string_new("anything");
        assert_that(str isnot NULL);
        assert_that(string_equals(str, string_new("anything")));
      });

      it("creates a new string exactly 1 char long", {
        char *str = string_new("a");
        assert_that(str isnot NULL);
        assert_that_charptr(str equals to "a");
      });

      it("creates a new string exactly 2 chars long", {
        char *str = string_new("ab");
        assert_that(str isnot NULL);
        assert_that_charptr(str equals to "ab");
      });

      it("creates a new string exactly 4 chars long", {
        char *str = string_new("1234");
        assert_that(str isnot NULL);
        assert_that_charptr(str equals to "1234");
      });

      it("creates a new string exactly 8 chars long", {
        char *str = string_new("12345678");
        assert_that(str isnot NULL);
        assert_that_charptr(str equals to "12345678");
      });

      it("creates a new string exactly 15 chars long", {
        char *str = string_new("123456789012345");
        assert_that(str isnot NULL);
        assert_that_charptr(str equals to "123456789012345");
      });

      it("creates a new string exactly 16 chars long", {
        char *str = string_new("1234567890123456");
        assert_that(str isnot NULL);
        assert_that_charptr(str equals to "1234567890123456");
      });

      it("creates a new string exactly 17 chars long", {
        char *str = string_new("12345678901234567");
        assert_that(str isnot NULL);
        assert_that_charptr(str equals to "12345678901234567");
      });

      it("creates a new string exactly 32 chars long", {
        char *str = string_new("1234567890123456789012345678901234567890");
        assert_that(str isnot NULL);
        assert_that_charptr(str equals to
                            "1234567890123456789012345678901234567890");
      });
    });

    context("on adding strings to a string", {
      it("adds a null string to a null string", {
        char *str = NULL;
        string_add(str, NULL);
        assert_that(str is NULL);
      });

      it("adds a null string to a valid string", {
        char *str = string_new("test");
        string_add(str, NULL);
        assert_that(str isnot NULL);
        assert_that_charptr(str equals to "test");
      });

      it("adds a valid string to a null string", {
        char *str = NULL;
        string_add(str, "test");
        assert_that(str isnot NULL);
        assert_that_charptr(str equals to "test");
      });

      it("adds a string to a string", {
        char *str        = NULL;
        char *str2       = string_new("test2");
        const char *str3 = "test3";
        string_add(str, str2);
        assert_that_charptr(str equals to "test2");
        assert_that_charptr(str2 equals to "test2");
        string_add(str, str3);
        assert_that_charptr(str equals to "test2test3");
        assert_that_charptr(str2 equals to "test2");
        assert_that_charptr(str3 equals to "test3");
      });

      it("adds an initialized string to a another string", {
        char *str        = NULL;
        char *str2       = string_new("test2");
        const char *str3 = "test3";

        string_addi(str, str2);
        assert_that_charptr(str equals to "test2");
        assert_that_charptr(str2 equals to "test2");

        string_add(str, str3);
        assert_that_charptr(str equals to "test2test3");
        assert_that_charptr(str2 equals to "test2");
        assert_that_charptr(str3 equals to "test3");
      });

      it("adds a string to a string with a format", {
        char *str        = NULL;
        char *str2       = string_new("test2");
        const char *str3 = "test3";
        string_addf(str, "%s%s", str2, str3, "ignored");
        assert_that_charptr(str equals to "test2test3");
        assert_that_charptr(str2 equals to "test2");
        assert_that_charptr(str3 equals to "test3");
        string_addf(str, "%s", "somethingelse");
        assert_that_charptr(str equals to "test2test3somethingelse");
      });
    });

    context("on adding literals to a string", {
      it("adds a simple character to a string", {
        char *str = NULL;
        string_add_char(str, 'a');
        assert_that_charptr(str equals to "a");
        string_add_char(str, 'b');
        assert_that_charptr(str equals to "ab");
        string_add_char(str, 'c');
        assert_that_charptr(str equals to "abc");
      });
    });

    context("when adding characters to a string it remains null terminated", {
      it("adds a simple character to a string", {
        char *input = string_new("$var!+(@another?)");
        char *token = string_substring(input, 0, 4);
        string_skip_first(input, 4);
        assert_that_charptr(token equals to "$var");
        assert_that_int(string_size(token) equals to 4);
        string_add_char(token, input[0]);
        string_skip_first(input, 1);
        assert_that_charptr(token equals to "$var!");
        assert_that_int(string_size(token) equals to 5);
        assert_that_int(string_size(input) equals to 12);
        assert_that_charptr(input equals to "+(@another?)");
      });
    });

    context("on a string pointer is not NULL", {
      it("returns the char* when calling `string_get`", {
        char *str = string_new("initial");
        assert_that(sizeof(str) is sizeof(char *));
      });
    });

    context("on the initial value exists", {
      it("returns the correct char* when calling `string_get`", {
        char *str = string_new("initial");
        assert_that_charptr(str equals to "initial");
      });
    });

    context("on #shorten/#skip/#ignore", {
      it("shortens a string to a given length", {
        char *str = string_new("this is a test");
        string_shorten(str, string_size(str) - 5);
        assert_that_charptr(str equals to "this is a");
      });

      it("shortens a string to a length shorter than the string size", {
        char *str = string_new("this is a test");
        string_shorten(str, string_size(str) - 42);
        assert_that_charptr(str equals to "");
      });

      it("shortens a string to a length greater than the string size", {
        char *str = string_new("this is a test");
        string_shorten(str, string_size(str) + 42);
        assert_that_charptr(str equals to "this is a test");
      });

      it("skips first string characters by a given length", {
        char *str = string_new("this is a test");
        string_skip_first(str, 5);
        assert_that_charptr(str equals to "is a test");
      });

      it("skips first string characters by a length greater than string size", {
        char *str = string_new("this is a test");
        string_skip_first(str, 42);
        assert_that_charptr(str equals to "");
      });

      it("skips first string characters by a length shorter than string size", {
        char *str = string_new("this is a test");
        string_skip_first(str, -42);
        assert_that_charptr(str equals to "this is a test");
      });

      it("ignores last string characters by a given length", {
        char *str = string_new("this is a test");
        string_ignore_last(str, 5);
        assert_that_charptr(str equals to "this is a");
      });

      it("ignores last string chars by a length greater than string size", {
        char *str = string_new("this is a test");
        string_ignore_last(str, 42);
        assert_that_charptr(str equals to "");
      });

      it("ignores last string chars by a length shorter than string size", {
        char *str = string_new("this is a test");
        string_ignore_last(str, -42);
        assert_that_charptr(str equals to "this is a test");
      });
    });

    it("clears a string", {
      char *str = string_new("this is a test");
      string_delete(str);
      assert_that_charptr(str equals to "");
    });

    it("finds the size of a string", {
      char *str = string_new("this is a test");
      assert_that_int(string_size(str) equals to 14);
    });

    it("tests equality between strings", {
      char *one = string_new("test");
      char *two = string_new("test");
      assert_that(string_equals(one, two));

      char *three = string_new("test");
      string_add(three, "sth else");
      nassert_that(string_equals(one, three));
    });

    context("#string_remove_underscores", {
      it("removes underscores from strings", {
        char *test = string_new("a_word_with_underscores");
        string_remove_underscores(test);
        assert_that_charptr(test equals to "awordwithunderscores");

        test = string_new("42_000_000");
        string_remove_underscores(test);
        printf("test: %s\n", test);
        assert_that_charptr(test equals to "42000000");
      });

      it("returns the same string if it doesn't contain underscores", {
        char *test = string_new("42");
        string_remove_underscores(test);
        assert_that_charptr(test equals to "42");
      });
    });

    context("on external function string manipulation", {
      it("adds a string that has been initialized", {
        char *test = string_new("initial");
        _external_string_add(&test, " - test");
        assert_that_charptr(test equals to "initial - test");
      });

      it("adds a string that has NOT been initialized", {
        char *test = string_new("");
        _external_string_add(&test, "this is an initial string");
        assert_that_charptr(test equals to "this is an initial string");
      });

      it("adds a string in a vector of strings in an extenral function", {
        char **v = vector_new("one");
        assert_that(vector_size(v) is 1);
        assert_that_charptr(v[0] equals to "one");
        char *two   = string_new("two");
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
        for(int i = 0; i < 20; i++) {
          _external_vector_add_int(&v, i);
        }

        for(int i = 0; i < 20; i++) {
          assert_that_int(v[i] equals to i);
        }

        assert_that_int(vector_size(v) equals to 20);
      });
    });

    it("frees the memory of a string", {
      char *str = string_new("this is a test");
      assert_that(str isnot NULL);
      string_free(str);
      assert_that(str is NULL);
    });
  });
})
