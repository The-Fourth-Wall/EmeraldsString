#include "../libs/cSpec/export/cSpec.h"
#include "string_base/string_base.module.spec.h"
#include "string_dup/string_dup.module.spec.h"
#include "string_functional_functions/string_functional_functions.module.spec.h"
#include "string_interpolation/string_interpolation.module.spec.h"
#include "string_split/string_split.module.spec.h"
#include "string_substring/string_substring.module.spec.h"

spec_suite({
  T_string_base();
  T_string_dup();
  T_string_functional_functions();
  T_string_interpolation();
  T_string_split();
  T_string_substring();
});

int main(void) { run_spec_suite("all"); }
