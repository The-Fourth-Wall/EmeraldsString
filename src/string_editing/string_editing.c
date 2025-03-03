#include "string_editing.h"

#include "../../libs/EmeraldsVector/export/EmeraldsVector.h"
#include "../string_base/string_base.h"
#include "../string_dup/string_dup.h"

char **string_split(char *self, const char delimeter) {
  char **str_tokens = NULL;
  char *tmp         = NULL;
  char *empty       = string_new("");

  if(self == NULL) {
    string_free(empty);
    return NULL;
  } else if(string_equals(self, empty)) {
    string_free(empty);
    vector_add(str_tokens, string_new(""));
  } else if(string_size(self) == 1 && self[0] == delimeter) {
    string_free(empty);
    vector_add(str_tokens, string_new(""));
    vector_add(str_tokens, string_new(""));
  } else {
    size_t i;
    string_free(empty);
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

char *
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

char *string_remove_underscores(char *self) {
  size_t i;
  for(i = 0; i < string_size(self); i++) {
    if(self[i] == '_') {
      string_remove(self, i);
    }
  }
  return self;
}
