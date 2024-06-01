#include "string_functional_functions.h"

void string_iterate(char *self, EmeraldsStringLambda apply) {
  if(self != NULL) {
    for(size_t i = 0; i < string_size(self); i++) {
      apply(self[i]);
    }
  }
}

char *string_map(char *self, EmeraldsStringLambda modifier) {
  if(self == NULL) {
    return NULL;
  } else {
    char *self_dup = string_new("");
    for(size_t i = 0; i < string_size(self); i++) {
      string_add_char(self_dup, modifier(self[i]));
    }
    return self_dup;
  }
}

char *string_filter(char *self, EmeraldsStringLambda filter) {
  if(self == NULL) {
    return NULL;
  } else {
    char *self_dup = string_new("");
    for(size_t i = 0; i < string_size(self); i++) {
      if(filter(self[i])) {
        string_add_char(self_dup, self[i]);
      }
    }
    return self_dup;
  }
}
