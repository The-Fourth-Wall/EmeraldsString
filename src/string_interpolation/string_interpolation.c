#include "string_interpolation.h"

#include <stdio.h> /* printf */

void string_display(size_t argc, ...) {
  char *self = string_new("");

  va_list vars;
  va_start(vars, argc)
    ;
    for(size_t i = 0; i < argc; i++) {
      char *v = va_arg(vars, char *);
      string_add(self, v);
    }
  va_end(vars);

  printf("displaying: %s\n", self);
  string_delete(self);
}
