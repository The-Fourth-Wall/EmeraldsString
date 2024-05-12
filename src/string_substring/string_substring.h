#ifndef __EMERALDS_STRING_SUBSTRING_H_
#define __EMERALDS_STRING_SUBSTRING_H_

#include "../string_base/string_base.h"
#include "../string_dup/string_dup.h"

/**
 * @brief Return a substring of our current string without modifying the
 *original
 * @param self -> The string builder we are using
 * @param from -> The point where we start our substring
 * @param to -> The point where we end our substring
 * @return A substring of a copy of the original string
 **/
EmeraldsString *
string_substring(EmeraldsString *self, size_t from, size_t __to);

#endif
