#include "../../libs/cSpec/export/cSpec.h"
#include "../../src/string_base/string_base.h"

module(T_string_base, {
  describe("string", {
    it("creates a new empty string", {
      char *str = string_new("");
      assert_that(str is NULL);
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
      test       = string_remove_underscores(test);
      assert_that_charptr(test equals to "awordwithunderscores");

      test = string_new("42_000_000");
      test = string_remove_underscores(test);
      assert_that_charptr(test equals to "42000000");
    });
  });
})
