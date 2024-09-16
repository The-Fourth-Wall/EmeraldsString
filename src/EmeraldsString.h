/**
 * A string builder implemented using memmove for crafting.
 *
 * Copyright (C) 2024 oblivious
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef __EMERALDS_STRING_H_
#define __EMERALDS_STRING_H_

#include "../libs/EmeraldsVector/export/EmeraldsVector.h"

#include <stdarg.h> /* va_list, va_start, va_end */
#include <stddef.h> /* ptrdiff_t */
#include <stdio.h>  /* vsnprintf */
#include <string.h> /* strncmp, strlen, memcpy */

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
 * @brief Adds a string with a cutoff of a given length
 * @param self -> The string to use
 * @param other -> The string to add
 * @param len -> The length of characters to add
 */
#define string_addn(self, other, len)       \
  do {                                      \
    if((self) == NULL && (other) != NULL) { \
      vector_initialize(self);              \
    }                                       \
    vector_add_n(self, other, (len) + 1);   \
    if((other) != NULL) {                   \
      string_ignore_last(self, 1);          \
    }                                       \
  } while(0)

/**
 * @brief Adds a string into self
 * @param self -> The string to use
 * @param other -> The string to add
 */
#define string_add(self, other) string_addn(self, other, strlen((other)))

/**
 * @brief Adds an initialized string into self
 * @param self -> The string to use
 * @param other -> The string to add
 */
#define string_addi(self, other) string_addn(self, other, string_size(other))

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
#define string_skip_first(self, _len)                     \
  do {                                                    \
    ptrdiff_t len = (ptrdiff_t)(_len);                    \
    if((self) != NULL) {                                  \
      if(len >= vector_size_signed(self)) {               \
        string_delete(self);                              \
      } else if(len > 0) {                                \
        _vector_get_header(self)->size -= len;            \
        memmove((self), (self) + len, string_size(self)); \
        (self)[string_size(self)] = '\0';                 \
      }                                                   \
    }                                                     \
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

#define string_remove(self, pos) \
  (vector_remove(self, pos), (self)[string_size(self)] = '\0')

/**
 * @brief Checks if the char pointers of the two strings passed are the same
 * @param self -> The first string
 * @param other -> The second string
 * @return A boolean signaling if the strings are equal
 **/
#define string_equals(self, other)           \
  ((string_size(self) == strlen((other))) && \
   (strncmp((self), (other), string_size(self)) == 0))

/**
 * @brief Removes all instances of `_` underscores
 * @param self -> The string to use
 */
#define string_remove_underscores(self)      \
  do {                                       \
    size_t i;                                \
    for(i = 0; i < string_size(self); i++) { \
      if(self[i] == '_') {                   \
        string_remove(self, i);              \
      }                                      \
    }                                        \
  } while(0)

/**
 * @brief Frees the memory of the string
 * @param self -> The string to free
 */
#define string_free(self) vector_free(self)

/**
 * @brief Create an string
 * @param initial_string -> The initial string to set
 * @return The string
 **/
p_inline char *string_new(const char *initial_string) {
  char *self = NULL;
  string_add(self, initial_string);
  return self;
}

/**
 * @brief Adds a formatted string into the builder
 * @param self -> The string to add to
 * @param f -> The format string to use
 * @param ... -> The rest of the arguments
 */
p_inline void string_addf(char **self, const char *f, ...) {
  signed int result = 0;
  /* TODO - Bounds checks */
  char buf[4096];
  va_list args;

  va_start(args, f)
    ;
    result = vsnprintf(buf, sizeof(buf), f, args);
  va_end(args);

  if(result >= 0) {
    string_add(*self, buf);
  }
}

p_inline char *string_dup(char *self) {
  char *dup = NULL;
  string_add(dup, self);
  return dup;
}

#define string_iterate(self, apply)          \
  do {                                       \
    size_t i;                                \
    for(i = 0; i < string_size(self); i++) { \
      apply(self[i]);                        \
    }                                        \
  } while(0)

p_inline char *string_map(char *self, EmeraldsStringLambda modifier) {
  if(self == NULL) {
    return NULL;
  } else {
    size_t i;
    char *self_dup = string_new("");
    for(i = 0; i < string_size(self); i++) {
      string_addf(&self_dup, "%c", modifier(self[i]));
    }
    return self_dup;
  }
}

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
p_inline void string_display(size_t argc, ...) {
  size_t i;
  char *self = string_new("");

  va_list vars;
  va_start(vars, argc)
    ;
    for(i = 0; i < argc; i++) {
      char *v = va_arg(vars, char *);
      if(v != NULL) {
        string_add(self, v);
      }
    }
  va_end(vars);

  printf("displaying: %s\n", self);
  string_delete(self);
}
#endif

/**
 * @brief Splits a string to a spesific delimeter
 * @param self -> The string to split
 * @param delimeter -> The char delimeter
 * @return A vector with the string tokens
 **/
p_inline char **string_split(char *self, const char delimeter) {
  char **str_tokens = NULL;
  char *tmp         = NULL;

  if(self == NULL) {
    return NULL;
  } else if(string_equals(self, string_new(""))) {
    vector_add(str_tokens, string_new(""));
  } else if(string_size(self) == 1 && self[0] == delimeter) {
    vector_add(str_tokens, string_new(""));
    vector_add(str_tokens, string_new(""));
  } else {
    size_t i;
    for(i = 0; i < string_size(self); i++) {
      if(self[i] == delimeter) {
        vector_add(str_tokens, string_new(tmp));
        string_free(tmp);
      } else {
        string_addf(&tmp, "%c", self[i]);
      }
    }

    vector_add(str_tokens, tmp);
  }

  return str_tokens;
}

/**
 * @brief Get a substring of our current string without modifying the original
 * @param self -> The string builder we are using
 * @param from_position -> The point where we start our substring
 * @param to_position -> The point where we end our substring
 * @return A substring of a copy of the original string
 **/
p_inline char *
string_substring(char *self, ptrdiff_t from_position, ptrdiff_t to_position) {
  char *strdup = string_dup(self);

  if(to_position < 0) {
    string_ignore_last(strdup, -to_position);
  } else {
    string_shorten(strdup, to_position);
  }

  if(from_position < 0) {
    string_skip_first(strdup, string_size(self) + from_position);
  } else {
    string_skip_first(strdup, from_position);
  }

  return strdup;
}

#endif
