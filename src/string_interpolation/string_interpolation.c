#include "string_interpolation.h"

void string_display(size_t argc, ...) {
  size_t i;
  EmeraldsString *sb = string_new("");

  va_list vars;
  va_start(vars, argc)
    ;
    for(i = 0; i < argc; i++) {
      string_add_str(sb, va_arg(vars, void *));
    }
  va_end(vars);

  printf("displaying: %s\n", string_get(sb));
  string_delete(sb);
}

/* TODO -> FIX SRC FOR C89 */
