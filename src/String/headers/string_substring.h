#ifndef __STRING_SUBSTRING_H_
#define __STRING_SUBSTRING_H_

#include "string_base.h"
#include "string_dup.h"

/**
 * @func: string_substring
 * @desc: Return a substring of our current string without modifying the original
 * @param sb -> The string builder we are using
 * @param from -> The point where we start our substring
 * @param to -> The point where we end our substring
 * @return A substring of a copy of the original string
 **/
string *string_substring(string *sb, size_t from, size_t __to);

#endif
