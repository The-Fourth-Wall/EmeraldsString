#ifndef __STRING_SPLIT_H_
#define __STRING_SPLIT_H_

#include "string_base.h"
#include "../../../libs/Vector/export/Vector.h"

/**
 * @func: string_split
 * @desc: Splits a string to a spesific delimeter
 * @param str -> The string to split
 * @param delimeter -> The string delimeter
 * @return A vector with the string tokens
 **/
vector *string_split(string *str, string *delimeter);

#endif
