#ifndef __EMERALDS_STRING_BASE_H_
#define __EMERALDS_STRING_BASE_H_

#include "../../libs/EmeraldsBool/export/EmeraldsBool.h"

#include <stdlib.h> /* malloc, calloc, realloc, free */

/** The initial minimum size of an EmeraldsString **/
static const size_t string_init_capacity = 32;

/**
 * @brief A mutable string of characters used to dynamically build a string.
 * @param str -> The str char* we construct our string into
 * @param alloced -> The total sized allocated for the string
 * @param length -> The total length of the string
 **/
typedef struct EmeraldsString {
  char *str;
  size_t alloced;
  size_t length;
} EmeraldsString;

/**
 * @brief Ensure there is enough space for data being added plus a NULL
 *terminator
 * @param sb -> The string builder to use
 * @param add_len -> he length that needs to be added *not* including a NULL
 *terminator
 **/
static void string_ensure_space(EmeraldsString *sb, size_t add_len);

/**
 * @brief Create an str builder
 * @param initial_string -> The initial string to set
 * @return The str builder
 **/
EmeraldsString *string_new(const char *initial_string);

/**
 * @brief Adds a string into self
 * @param self -> The str builder to use
 * @param other -> The str builder to add
 */
void string_add(EmeraldsString *self, EmeraldsString *other);

/**
 * @brief Adds a formatted string into the builder
 * @param sb -> The str builder ot add to
 * @param f -> The format string to use
 * @param ... -> The rest of the arguments
 */
void string_addf(EmeraldsString *sb, const char *f, ...);

/**
 * @brief Add a string to the builder
 * @param sb -> The string builder to use
 * @param str -> The string to add
 * @param len -> The length of the string to add.
 *              If 0, strlen will be called internally to determine length
 **/
void string_add_str(EmeraldsString *sb, const char *str);

/**
 * @brief Add a character to the builder
 * @param sb -> The string builder to use
 * @param c -> The character to add
 **/
void string_add_char(EmeraldsString *sb, char c);

/**
 * @brief Add an integer to the builder
 * @param sb -> The string builder to use
 * @param val -> The integer to add
 **/
void string_add_int(EmeraldsString *sb, int val);

/**
 * @brief Add a double to the builder
 * @param sb -> The string builder to use
 * @param val -> The double to add
 **/
void string_add_double_precision(EmeraldsString *sb, double val);

/**
 * @brief A pointer to the internal buffer with the builder's stirng data
 * @param sb -> The string builder to use
 * @return A pointer to the internal string data
 **/
char *string_get(EmeraldsString *sb);

/**
 * @brief Accessor to the string characters by index
 * @param sb -> The string builder to use
 * @param index -> The index of the character we want to receive
 * @return The character we searched for
 **/
char string_get_char_at_index(EmeraldsString *sb, size_t index);

/**
 * @brief Remove data from the end of the builder
 * @param sb -> The string builder to use
 * @param len -> The new length of the string, anything after this length is
 *removed
 **/
void string_shorten(EmeraldsString *sb, size_t len);

/**
 * @brief Clear the builder
 * @param sb -> The string builder to use
 **/
void string_delete(EmeraldsString *sb);

/**
 * @brief Remove data from the beginning of the builder
 * @param sb -> The string builder to use
 * @param len -> The length to remove
 **/
void string_skip(EmeraldsString *sb, size_t len);

/**
 * @brief The length of the string contained in the builder
 * @param sb -> The string builder to use
 * @return The current length of the string
 **/
size_t string_size(EmeraldsString *sb);

/**
 * @brief Checks if the char pointers of the two strings passed are the same
 * @param sb -> The first string
 * @param other -> The second string
 * @return A boolean signaling if the strings are equal
 **/
bool string_equals(EmeraldsString *sb, EmeraldsString *other);

/**
 * @brief Turns a string into a valid identifier by
 *  converting illegal characters to hex codes
 * @param sb -> The string builder to convert
 * @return A valid char pointer identifier
 **/
char *string_identifier(EmeraldsString *sb);

/**
 * @brief Removes all instances of `_` underscores
 * @param self -> The string builder to use
 * @return The edited string builder
 */
EmeraldsString *string_remove_underscores(EmeraldsString *self);

/**
 * @brief Frees the memory of the string
 * @param sb -> The string to free
 */
void string_free(EmeraldsString *sb);

#endif
