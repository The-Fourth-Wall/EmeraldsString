#include "string_substring.h"

char *string_substring(char *self, size_t from_position, size_t to_position) {
  char *strdup = string_dup(self);
  string_skip(strdup, from_position);
  string_shorten(strdup, to_position - from_position + 1);
  return strdup;
}
