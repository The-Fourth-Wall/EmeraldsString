#include "string_substring.h"

char *string_substring(char *self, size_t from_position, size_t to_position) {
  char *strdup = string_dup(self);
  string_skip_first(strdup, from_position);
  string_ignore_last(strdup, to_position);
  return strdup;
}
