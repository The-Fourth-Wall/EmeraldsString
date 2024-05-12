#include "string_split.h"

#include "../string_dup/string_dup.h"

#include <string.h> /* strtok */

EmeraldsVector *string_split(EmeraldsString *self, EmeraldsString *delimeter) {
  EmeraldsVector *str_tokens = vector_new();
  EmeraldsString *dup        = string_dup(self);
  char *token_ptr            = string_get(dup);

  /* TODO -> IMPROVE SPEED */
  /* Iterate through the chars constructing a string and
    reseting the value once we find the delimeter */
  token_ptr = strtok(string_get(dup), string_get(delimeter));
  while(token_ptr != NULL) {
    vector_add(str_tokens, string_new(token_ptr));
    token_ptr = strtok(NULL, string_get(delimeter));
  }

  return str_tokens;
}
