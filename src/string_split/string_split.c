#include "string_split.h"

#include "../string_dup/string_dup.h"

#include <string.h> /* strtok */

char **string_split(char *self, char *delimeter) {
  char **str_tokens = NULL;
  char *dup         = string_dup(self);

  /* TODO -> IMPROVE SPEED */
  /* Iterate through the chars constructing a string and
    reseting the value once we find the delimeter */
  dup = strtok(dup, delimeter);
  while(dup != NULL) {
    vector_add(str_tokens, string_new(dup));
    dup = strtok(NULL, delimeter);
  }

  return str_tokens;
}
