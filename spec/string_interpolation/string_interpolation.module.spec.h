#include "../../libs/cSpec/export/cSpec.h"
#include "../../src/string_base/string_base.h"
#include "../../src/string_interpolation/string_interpolation.h"

module(T_string_interpolation, {
  describe("string interpolation", {
    it("displays a null string", {
      char *str = NULL;
      string_puts(str);
    });

    it("displays an empty string", {
      char *str = string_new("");
      string_puts(str);
    });

    it("displays a string", {
      char *str = string_new("test");
      string_puts(str);
    });
  });
})
