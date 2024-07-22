#include "string_dup.h"

#include "../string_base/string_base.h"

char *string_dup(char *self) {
  if(self == NULL) {
    return NULL;
  } else {
    char *dup = string_new("");
    string_add(dup, self);
    return dup;
  }
}
