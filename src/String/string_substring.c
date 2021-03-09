#include "headers/string_substring.h"

string *string_substring(string *str, size_t str_position_from, size_t str_position_to) {
    string *strdup = string_dup(str);
    string_skip(strdup, str_position_from);
    string_shorten(strdup, str_position_to - str_position_from + 1);
    return strdup;
}
