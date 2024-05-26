#include "string_dup.h"

char *string_dup(char *self) {
  if(self == NULL) {
    return NULL;
  } else {
    char *dup = string_new("");
    string_add(dup, self);
    return dup;
  }
}
