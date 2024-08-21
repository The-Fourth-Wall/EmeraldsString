#include "string_base.h"

#include <stdio.h> /* vsnprintf */

char *string_new(const char *initial_string) {
  char *self = NULL;
  string_add(self, initial_string);
  return self;
}

void string_addf(char **self, const char *f, ...) {
  signed int result = 0;
  /* TODO - Bounds checks */
  char buf[4096];
  va_list args;

  va_start(args, f)
    ;
    result = vsnprintf(buf, sizeof(buf), f, args);
  va_end(args);

  if(result >= 0) {
    string_add(*self, buf);
  }
}
