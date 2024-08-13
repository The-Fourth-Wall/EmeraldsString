#ifndef __EMERALDS_STRING_SUBSTRING_H_
#define __EMERALDS_STRING_SUBSTRING_H_

#include <stddef.h> /* ptrdiff_t */

/**
 * @brief Get a substring of our current string without modifying the original
 * @param self -> The string builder we are using
 * @param from_position -> The point where we start our substring
 * @param to_position -> The point where we end our substring
 * @return A substring of a copy of the original string
 **/
char *
string_substring(char *self, ptrdiff_t from_position, ptrdiff_t to_position);

#endif
