#ifndef __EMERALDS_STRING_FUNCTIONAL_FUNCTIONS_H_
#define __EMERALDS_STRING_FUNCTIONAL_FUNCTIONS_H_

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
 * @param self -> The string builder we want to iterate
 * @param apply -> The function we apply to each character
 **/
void string_iterate(char *self, EmeraldsStringLambda apply);

/**
 * @brief Maps each character of the string according to a modifier function
 * @param self -> The string builder to map
 * @param modifier -> The EmeraldsStringLambda function to use for the
 *conversions
 * @return A new mapped string
 **/
char *string_map(char *self, EmeraldsStringLambda modifier);

#endif
