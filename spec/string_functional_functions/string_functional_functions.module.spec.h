#include "../../libs/cSpec/export/cSpec.h"
#include "../../src/string_base/string_base.h"
#include "../../src/string_functional_functions/string_functional_functions.h"

static void iterator(char c) { printf("iterating: %c\n", c); }

static char map(char c) { return c + 1; }

static char filter(char c) { return c < 'm'; }

module(T_string_functional_functions, {
  describe("string functional functions", {
    context("on iterating", {
      it("iterates through a null string", {
        char *str = NULL;
        string_iterate(str, (EmeraldsStringLambda)iterator);
      });

      it("iterates through an empty string", {
        char *str = string_new("");
        string_iterate(str, (EmeraldsStringLambda)iterator);
      });

      it("iterates through a string", {
        char *str = string_new("oblivious");
        string_iterate(str, (EmeraldsStringLambda)iterator);
      });
    });

    context("on mapping", {
      it("maps a null string", {
        char *str    = NULL;
        char *mapped = string_map(str, (EmeraldsStringLambda)map);
        assert_that(str is NULL);
        assert_that(mapped is NULL);
      });

      it("maps an empty string", {
        char *str    = string_new("");
        char *mapped = string_map(str, (EmeraldsStringLambda)map);
        assert_that(str isnot NULL);
        assert_that(mapped isnot NULL);
        assert_that_charptr(str equals to "");
        assert_that_charptr(mapped equals to "");
      });

      it("maps a string", {
        char *str    = string_new("oblivious");
        char *mapped = string_map(str, (EmeraldsStringLambda)map);
        assert_that(str isnot NULL);
        assert_that(mapped isnot NULL);
        assert_that_charptr(str equals to "oblivious");
        assert_that_charptr(mapped equals to "pcmjwjpvt");
      });
    });
  });
})
