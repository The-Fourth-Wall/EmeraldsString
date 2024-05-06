#ifndef __EMERALDS_STRING_FUNCTIONAL_FUNCTIONS_H_
#define __EMERALDS_STRING_FUNCTIONAL_FUNCTIONS_H_

#include "../string_base/string_base.h"

/**
 * @brief A generic function type used upon iterable data structures
 * @param -> An element belonging to an iterable
 * @return -> A value that satisfies the callee's purpose (map, filter, reduce)
 **/
/* The param void* can have more than 1 argument stored as a list of some sort
 */
/* Since this is completely generic we can't check for validity of arguments */
/* The validity of the function is dependent on the callee */
typedef char (*EmeraldsStringLambda)(char);

/**
 * @brief Iterates through the characters of the string
 * @param sb -> The string builder we want to iterate
 * @param apply -> The function we apply to each character
 **/
void string_iterate(EmeraldsString *sb, EmeraldsStringLambda apply);

/**
 * @brief Maps each character of the string according to a modifier function
 * @param sb -> The string builder to map
 * @param modifier -> The EmeraldsStringLambda function to use for the
 *conversions
 * @return A new mapped string
 **/
EmeraldsString *string_map(EmeraldsString *sb, EmeraldsStringLambda modifier);

/**
 * @brief Filters out characters from the string according to a function
 * @param sb -> The string builder to filter
 * @param filter -> The labmda function to use
 * @return A new filtered string
 **/
EmeraldsString *string_filter(EmeraldsString *sb, EmeraldsStringLambda filter);

#endif
