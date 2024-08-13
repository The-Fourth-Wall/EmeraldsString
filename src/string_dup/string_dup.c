#include "string_dup.h"

#include "../string_base/string_base.h"

char *string_dup(char *self) {
  char *dup = NULL;
  string_add(dup, self);
  return dup;
}
