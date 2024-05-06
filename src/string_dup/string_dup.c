#include "string_dup.h"

EmeraldsString *string_dup(EmeraldsString *sb) {
  EmeraldsString *dup = NULL;

  if(sb == NULL) {
    return NULL;
  }

  dup = string_new("");
  string_add_str(dup, string_get(sb));

  return dup;
}
