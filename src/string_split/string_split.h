#ifndef __EMERALDS_STRING_SPLIT_H_
#define __EMERALDS_STRING_SPLIT_H_

/**
 * @brief Splits a string to a spesific delimeter
 * @param self -> The string to split
 * @param delimeter -> The char delimeter
 * @return A vector with the string tokens
 **/
char **string_split(char *self, const char delimeter);

#endif
