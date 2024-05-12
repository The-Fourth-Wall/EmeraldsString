#include "string_dup.h"

EmeraldsString *string_dup(EmeraldsString *self) {
  EmeraldsString *dup = NULL;

  if(self == NULL) {
    return NULL;
  }

  dup = string_new("");
  string_add_str(dup, string_get(self));

  return dup;
}
