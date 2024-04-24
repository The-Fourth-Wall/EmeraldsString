#include "String.spec.h"

module(T_String, {
  describe("#get_value", {
    it("returns `Hello, World!`", {
      assert_that_charptr("Hello, World!" equals to "Hello, World!");
    });
  });
})

spec_suite({
  T_String();
})

int main(void) {
  run_spec_suite("all");
}
