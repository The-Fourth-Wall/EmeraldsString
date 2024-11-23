#ifndef __STRING_FUNCTIONAL_H_
#define __STRING_FUNCTIONAL_H_

#include "../../libs/EmeraldsVector/export/EmeraldsVector.h"

#if PREPROCESSOR_C_VERSION >= 1999
  #define string_puts(...)                                                 \
    string_display(                                                        \
      PREPROCESSOR_EXPANSIONS_NUMBER_OF_ELEMENTS(__VA_ARGS__), __VA_ARGS__ \
    )

/* TODO - Actual conversion to a string */
/**
 * @brief Used for string interpolation
 * @param argc -> The number of the arguments provided by the macros
 * @param __VA_ARGS__ -> The rest of the arguments to iterate through
 **/
void string_display(size_t argc, ...);
#endif

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
char *string_iterate(char *self, EmeraldsStringLambda apply);

/**
 * @brief Maps each character of the string according to a modifier function
 * @param self -> The string builder to map
 * @param modifier -> The EmeraldsStringLambda function to use for the
 *conversions
 * @return A new mapped string
 **/
char *string_map(char *self, EmeraldsStringLambda modifier);

#endif
