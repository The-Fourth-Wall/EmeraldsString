#include "string_substring.h"

#include "../string_base/string_base.h"
#include "../string_dup/string_dup.h"

char *
string_substring(char *self, ptrdiff_t from_position, ptrdiff_t to_position) {
  char *strdup = string_dup(self);

  if(to_position < 0) {
    string_ignore_last(strdup, -to_position);
  } else {
    string_shorten(strdup, to_position);
  }

  if(from_position < 0) {
    string_skip_first(strdup, string_size(self) + from_position);
  } else {
    string_skip_first(strdup, from_position);
  }

  return strdup;
}
