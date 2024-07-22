#include "../../libs/cSpec/export/cSpec.h"
#include "../../src/string_base/string_base.h"
#include "../../src/string_dup/string_dup.h"

module(T_string_dup, {
  describe("string dup", {
    it("returns a copy of the string", {
      char *str = string_new("test");
      char *dup = string_dup(str);
      assert_that(str isnot NULL);
      assert_that(dup isnot NULL);
      assert_that_charptr(str equals to "test");
      assert_that_charptr(dup equals to "test");
    });

    it("returns null when given null", {
      char *str = NULL;
      char *dup = string_dup(str);
      assert_that(str is NULL);
      assert_that(dup is NULL);
    });

    it("returns an empty non-null string when given an empty string", {
      char *str = string_new("");
      char *dup = string_dup(str);
      assert_that(str isnot NULL);
      assert_that(dup isnot NULL);
      assert_that_charptr(str equals to "");
      assert_that_charptr(dup equals to "");
    });

    it("returns a copy not a reference", {
      char *str = string_new("test");
      char *dup = string_dup(str);
      string_add(str, " on str");
      string_add(dup, " on dup");
      assert_that_charptr(str equals to "test on str");
      assert_that_charptr(dup equals to "test on dup");
    });
  });
})
