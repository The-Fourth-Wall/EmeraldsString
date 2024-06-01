#include "string_split.h"

#include "../string_dup/string_dup.h"

#include <string.h> /* strtok */

char **string_split(char *self, const char *delimeter) {
  char **str_tokens = NULL;
  char *dup         = string_dup(self);

  if(self == NULL) {
    return NULL;
  } else if(delimeter == NULL) {
    vector_add(str_tokens, self);
  } else if(string_equals(self, "")) {
    vector_add(str_tokens, string_new(""));
  } else if(string_equals(self, delimeter)) {
    vector_add(str_tokens, string_new(""));
    vector_add(str_tokens, string_new(""));
  } else {
    /* TODO - Improve speed: Iterate through the chars constructing a string and
     * reseting the value once we find the delimeter */
    dup = strtok(dup, delimeter);
    while(dup != NULL) {
      vector_add(str_tokens, string_new(dup));
      dup = strtok(NULL, delimeter);
    }
  }

  return str_tokens;
}
