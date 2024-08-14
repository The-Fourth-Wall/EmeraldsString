#ifndef __EMERALDS_STRING_BASE_H_
#define __EMERALDS_STRING_BASE_H_

#include "../../libs/EmeraldsVector/export/EmeraldsVector.h"

#include <string.h> /* strlen, memcpy */

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
#define string_add(self, other)               \
  do {                                        \
    if(self == NULL && other != NULL) {       \
      vector_initialize(self);                \
    }                                         \
    vector_add_n(self, other, strlen(other)); \
  } while(0)

#define string_addi(self, other)                   \
  do {                                             \
    if(self == NULL) {                             \
      vector_initialize(self);                     \
    }                                              \
    vector_add_n(self, other, string_size(other)); \
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
#define string_add_char(self, c) \
  (vector_add(self, c), (self)[vector_size(self)] = '\0')

/**
 * @brief The length of the string contained in the builder
 * @param self -> The string to use
 * @return The current length of the string
 **/
#define string_size(self) vector_size(self)

/**
 * @brief Signed length
 * @param self -> The string to use
 * @return The current length of the string as a signed integer
 */
#define string_size_signed(self) vector_size_signed(self)

/**
 * @brief Remove data from the end of the builder
 * @param self -> The string to use
 * @param len -> The new length , anything after this length is removed
 **/
#define string_shorten(self, _len)                \
  do {                                            \
    ptrdiff_t len = (ptrdiff_t)(_len);            \
    if((self) != NULL) {                          \
      if(len < 0) {                               \
        _vector_get_header(self)->size = 0;       \
      } else if(len < vector_size_signed(self)) { \
        _vector_get_header(self)->size = len;     \
      }                                           \
      (self)[string_size(self)] = '\0';           \
    }                                             \
  } while(0)

/**
 * @brief Remove data from the beginning of the builder
 * @param self -> The string to use
 * @param len -> The length to remove
 **/
#define string_skip_first(self, _len)                        \
  do {                                                       \
    ptrdiff_t len = (ptrdiff_t)(_len);                       \
    if((self) != NULL) {                                     \
      if(len >= vector_size_signed(self)) {                  \
        string_delete(self);                                 \
      } else if(len > 0) {                                   \
        _vector_get_header(self)->size -= len;               \
        /* NOTE +1 to move the NULL. */                      \
        memcpy((self), (self) + len, string_size(self) + 1); \
      }                                                      \
    }                                                        \
  } while(0)

/**
 * @brief Ignores the last `len` characters of the string
 * @param self -> The string to use
 * @param len -> The length to ignore
 **/
#define string_ignore_last(self, len) \
  string_shorten(self, string_size(self) - len)

/**
 * @brief Clear the builder
 * @param self -> The string to use
 **/
#define string_delete(self) string_shorten(self, 0)

/**
 * @brief Checks if the char pointers of the two strings passed are the same
 * @param self -> The first string
 * @param other -> The second string
 * @return A boolean signaling if the strings are equal
 **/
#define string_equals(self, other) (strcmp((self), (other)) == 0)

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
