#include "string_interpolation.h"

#include "../string_base/string_base.h"

#include <stdio.h> /* printf */

#if PREPROCESSOR_C_VERSION >= 1999
void string_display(size_t argc, ...) {
  size_t i;
  char *self = string_new("");

  va_list vars;
  va_start(vars, argc)
    ;
    for(i = 0; i < argc; i++) {
      char *v = va_arg(vars, char *);
      if(v != NULL) {
        string_add(self, v);
      }
    }
  va_end(vars);

  printf("displaying: %s\n", self);
  string_delete(self);
}
#endif
