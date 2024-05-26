#ifndef __EMERALDS_STRING_SPLIT_H_
#define __EMERALDS_STRING_SPLIT_H_

#include "../../libs/EmeraldsVector/export/EmeraldsVector.h"
#include "../string_base/string_base.h"

/**
 * @brief Splits a string to a spesific delimeter
 * @param self -> The string to split
 * @param delimeter -> The string delimeter
 * @return A vector with the string tokens
 **/
char **string_split(char *self, char *delimeter);

#endif
