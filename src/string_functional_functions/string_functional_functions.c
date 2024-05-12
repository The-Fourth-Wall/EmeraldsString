#include "string_functional_functions.h"

void string_iterate(EmeraldsString *self, EmeraldsStringLambda apply) {
  char *self_str = NULL;
  size_t i;

  if(self == NULL || apply == NULL) {
    return;
  }

  self_str = string_get(self);

  for(i = 0; i < string_size(self); i++) {
    apply(self_str[i]);
  }
}

EmeraldsString *
string_map(EmeraldsString *self, EmeraldsStringLambda modifier) {
  char *self_str           = NULL;
  EmeraldsString *self_dup = NULL;
  size_t i;

  if(self == NULL || modifier == NULL) {
    return NULL;
  }

  self_str = string_get(self);
  self_dup = string_new("");

  for(i = 0; i < string_size(self); i++) {
    string_add_char(self_dup, modifier(self_str[i]));
  }

  return self_dup;
}

EmeraldsString *
string_filter(EmeraldsString *self, EmeraldsStringLambda filter) {
  char *self_str           = NULL;
  EmeraldsString *self_dup = NULL;
  size_t i;

  if(self == NULL || filter == NULL) {
    return NULL;
  }

  self_str = string_get(self);
  self_dup = string_new("");

  for(i = 0; i < string_size(self); i++) {
    if(filter(self_str[i])) {
      string_add_char(self_dup, self_str[i]);
    }
  }

  return self_dup;
}
