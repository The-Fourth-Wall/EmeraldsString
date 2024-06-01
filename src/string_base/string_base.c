#include "string_base.h"

#include "../../libs/EmeraldsVector/export/EmeraldsVector.h" /* IWYU pragma: keep */

#include <stdarg.h> /* va_start, va_end, va_arg */
#include <stdio.h>  /* printf, snprintf, vsnprintf */
#include <string.h> /* strlen, strcmp, memmove */

char *string_new(const char *initial_string) {
  char *self = NULL;
  string_add(self, initial_string);
  return self;
}

void _string_internal_addf(char **self, const char *f, ...) {
  signed int result = 0;
  /* TODO -> BOUNDS CHECKS */
  char buf[65536];
  va_list args;

  va_start(args, f)
    ;
    result = vsnprintf(buf, sizeof(buf), f, args);
  va_end(args);

  if(result >= 0) {
    string_add(*self, buf);
  }
}

void string_shorten(char *self, size_t len) {
  if(len < string_size(self)) {
    _vector_internal_get_header(self)->size = len;
    self[string_size(self)]                 = '\0';
  }
}

void string_skip_first(char *self, size_t len) {
  if(len >= string_size(self)) {
    /* If we choose to drop more bytes than the
        string has simply clear the char */
    string_delete(self);
  } else {
    _vector_internal_get_header(self)->size -= len;
    /* +1 to move the NULL. */
    memmove(self, self + len, string_size(self) + 1);
  }
}

char *string_identifier(char *self) {
  unsigned char add_underscore = 0;
  char buf[32];
  size_t i;
  char *output    = NULL;
  char *ret_value = NULL;

  if(self == NULL) {
    return "";
  }

  output = string_new("");

  for(i = 0; i < string_size(self); i++) {
    char c = self[i];

    if(i == 0 && c >= '0' && c <= '9') {
      string_add_char(output, '_');
      string_add_char(output, c);
    } else if((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') ||
              (c >= 'a' && c != '_' && c <= 'z')) {
      string_add_char(output, c);
    } else if(c == 32) {
      string_add_char(output, '_');
    } else {
      if(i == 0) {
        add_underscore = 1;
      }
      snprintf(buf, 2, "%02x", c & 0xff);
      string_add(output, buf);
    }
  }

  if(add_underscore) {
    ret_value = string_new("_");
  } else {
    ret_value = string_new("");
  }
  string_add(ret_value, output);

  return ret_value;
}

char *string_remove_underscores(char *self) {
  char *self_dup = string_new("");

  for(size_t i = 0; i < string_size(self); i++) {
    if(self[i] != '_') {
      string_add_char(self_dup, self[i]);
    }
  }

  return self_dup;
}
