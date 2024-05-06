#include "string_substring.h"

EmeraldsString *string_substring(
  EmeraldsString *str, size_t str_position_from, size_t str_position_to
) {
  EmeraldsString *strdup = string_dup(str);
  string_skip(strdup, str_position_from);
  string_shorten(strdup, str_position_to - str_position_from + 1);
  return strdup;
}