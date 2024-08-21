#ifndef __EMERALDS_STRING_INTERPOLATION_H_
#define __EMERALDS_STRING_INTERPOLATION_H_

#include "../../libs/EmeraldsPreprocessor/export/EmeraldsPreprocessor.h"

#include <stdlib.h> /* size_t */

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

#endif
