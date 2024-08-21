#include "string_split.h"

#include "../string_base/string_base.h"

char **string_split(char *self, const char delimeter) {
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
