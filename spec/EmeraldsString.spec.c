#include "../libs/cSpec/export/cSpec.h"
#include "string_base.module.spec.h"
#include "string_dup.module.spec.h"
#include "string_functional_functions.module.spec.h"
#include "string_interpolation.module.spec.h"
#include "string_split.module.spec.h"
#include "string_substring.module.spec.h"

int main(void) {
  cspec_run_suite("all", {
    T_string_base();
    T_string_dup();
    T_string_functional_functions();
    T_string_interpolation();
    T_string_split();
    T_string_substring();
  });
}
