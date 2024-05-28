#ifndef __EMERALDS_STRING_BASE_H_
#define __EMERALDS_STRING_BASE_H_

#include "../../libs/EmeraldsVector/export/EmeraldsVector.h"

#include <string.h> /* strlen */

/**
 * @brief Create an string
 * @param initial_string -> The initial string to set
 * @return The string
 **/
char *string_new(const char *initial_string);

/**
 * @brief Adds a string into self
 * @param self -> The string to use
 * @param other -> The string to add
 */
#define string_add(self, other)       \
  do {                                \
    size_t len = strlen(other);       \
    for(size_t i = 0; i < len; i++) { \
      vector_add(self, other[i]);     \
    }                                 \
  } while(0)

/**
 * @brief Adds a formatted string into the builder
 * @param self -> The string to add to
 * @param f -> The format string to use
 * @param ... -> The rest of the arguments
 */
void _string_internal_addf(char **self, const char *f, ...);
#define string_addf(self, f, ...) _string_internal_addf(&self, f, __VA_ARGS__)

/**
 * @brief Add a character to the builder
 * @param self -> The string to use
 * @param c -> The character to add
 **/
#define string_add_char(self, c) vector_add(self, c)

/**
 * @brief Add an integer to the builder
 * @param self -> The string to use
 * @param val -> The integer to add
 **/
#define string_add_int(self, val)          \
  do {                                     \
    char str[32];                          \
    snprintf(str, sizeof(str), "%d", val); \
    string_add(self, str);                 \
  } while(0)

/**
 * @brief Add a double to the builder
 * @param self -> The string to use
 * @param val -> The double to add
 **/
#define string_add_double_precision(self, val) \
  do {                                         \
    char str[64];                              \
    snprintf(str, sizeof(str), "%g", val);     \
    string_add(self, str);                     \
  } while(0)

/**
 * @brief Remove data from the end of the builder
 * @param self -> The string to use
 * @param len -> The new length of the string, anything after this length is
 *removed
 **/
void string_shorten(char *self, size_t len);

/**
 * @brief Clear the builder
 * @param self -> The string to use
 **/
#define string_delete(self) string_shorten(self, 0)

/**
 * @brief Remove data from the beginning of the builder
 * @param self -> The string to use
 * @param len -> The length to remove
 **/
void string_skip(char *self, size_t len);

/**
 * @brief The length of the string contained in the builder
 * @param self -> The string to use
 * @return The current length of the string
 **/
#define string_size(self) vector_size(self)

/**
 * @brief Checks if the char pointers of the two strings passed are the same
 * @param self -> The first string
 * @param other -> The second string
 * @return A boolean signaling if the strings are equal
 **/
#define string_equals(self, other) (strcmp((self), (other)) == 0)

/**
 * @brief Turns a string into a valid identifier by
 *  converting illegal characters to hex codes
 * @param self -> The string to convert
 * @return A valid char pointer identifier
 **/
char *string_identifier(char *self);

/**
 * @brief Removes all instances of `_` underscores
 * @param self -> The string to use
 * @return The edited string
 */
char *string_remove_underscores(char *self);

/**
 * @brief Frees the memory of the string
 * @param self -> The string to free
 */
#define string_free(self) vector_free(self)

#endif
