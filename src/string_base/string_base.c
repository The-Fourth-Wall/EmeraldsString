#include "string_base.h"

#include <stdarg.h> /* va_start, va_end, va_arg */
#include <stdio.h>  /* printf, snprintf, vsnprintf */
#include <string.h> /* strlen, strcmp, memmove */

/** The increase rate of an EmeraldsString */
static const double string_golden_mean = 1.618;

/** The initial minimum size of an EmeraldsString **/
static const size_t string_init_capacity = 1024;

static void string_ensure_space(EmeraldsString *self, size_t add_len) {
  char *new_str = NULL;
  if(self == NULL || add_len == 0) {
    return;
  }

  /* Attempt to reallocate new memory in the items list */
  new_str = (char *)realloc(self->str, sizeof(char *) * add_len);

  if(new_str) {
    /* Reset the items in the new memory space */
    self->str     = new_str;
    self->alloced = add_len;
  }
}

EmeraldsString *string_new(const char *initial_string) {
  EmeraldsString *self = (EmeraldsString *)malloc(sizeof(EmeraldsString));
  self->str            = (char *)malloc(sizeof(char) * string_init_capacity);

  /* NULL terminate the EmeraldsString */
  *self->str = '\0';

  self->alloced = string_init_capacity;
  self->size    = 0;

  string_add_str(self, initial_string);
  return self;
}

void string_add(EmeraldsString *self, EmeraldsString *other) {
  if(self == NULL || other == NULL) {
    return;
  }
  string_add_str(self, other->str);
}

void string_addf(EmeraldsString *self, const char *f, ...) {
  signed int result = 0;
  char buf[BIG_NUMBA];
  va_list args;

  va_start(args, f)
    ;
    result = vsnprintf(buf, sizeof(buf), f, args);
  va_end(args);

  if(result < 0) {
    return;
  }

  string_add_str(self, buf);
}

void string_add_str(EmeraldsString *self, const char *str) {
  size_t len;

  if(self == NULL || str == NULL || *str == '\0') {
    return;
  }

  len = strlen(str);

  if(self->alloced < self->size + len) {
    string_ensure_space(self, self->alloced * string_golden_mean);
  }

  /* Copy the value into memory */
  memmove(self->str + self->size, str, len);

  /* Reset length and NULL terminate */
  self->size += len;
  self->str[self->size] = '\0';
}

void string_add_char(EmeraldsString *self, char c) {
  if(self == NULL) {
    return;
  }

  if(self->alloced < self->size + 1) {
    string_ensure_space(self, self->alloced * string_golden_mean);
  }

  self->str[self->size] = c;
  self->size++;
  self->str[self->size] = '\0';
}

void string_add_int(EmeraldsString *self, int val) {
  char str[32];

  if(self == NULL) {
    return;
  }

  snprintf(str, sizeof(str), "%d", val);
  string_add_str(self, str);
}

void string_add_double_precision(EmeraldsString *self, double val) {
  char str[64];

  if(self == NULL) {
    return;
  }

  /* Use %g for minimum precision on printing floats */
  snprintf(str, sizeof(str), "%g", val);
  string_add_str(self, str);
}

char *string_get(EmeraldsString *self) {
  if(self == NULL) {
    return NULL;
  }
  return self->str;
}

char string_get_char_at_index(EmeraldsString *self, size_t index) {
  if(self == NULL) {
    return '\0';
  }
  return self->str[index];
}

void string_shorten(EmeraldsString *self, size_t len) {
  if(self == NULL || len >= self->size) {
    return;
  }

  /* Reset the length and NULL terminate, ingoring
      all values right to the NULL from memory */
  self->size            = len;
  self->str[self->size] = '\0';
}

void string_delete(EmeraldsString *self) {
  if(self == NULL) {
    return;
  }

  /* Call shorten with 0, clearing out the EmeraldsString */
  string_shorten(self, 0);

  /* TODO -> Prob wrong idea */
  /*string_free(self);*/
}

void string_skip(EmeraldsString *self, size_t len) {
  if(self == NULL || len == 0) {
    return;
  }

  if(len >= self->size) {
    /* If we choose to drop more bytes than the
        string has simply clear the EmeraldsString */
    string_delete(self);
    return;
  }

  self->size -= len;

  /* +1 to move the NULL. */
  memmove(self->str, self->str + len, self->size + 1);
}

size_t string_size(EmeraldsString *self) {
  if(self == NULL) {
    return 0;
  }
  return self->size;
}

bool string_equals(EmeraldsString *self, EmeraldsString *other) {
  return strcmp(string_get(self), string_get(other)) == 0;
}

char *string_identifier(EmeraldsString *self) {
  unsigned char add_underscore = 0;
  char buf[32];
  size_t i;
  EmeraldsString *output    = NULL;
  EmeraldsString *ret_value = NULL;

  if(self == NULL) {
    return NULL;
  }

  output = string_new("");

  for(i = 0; i < string_size(self); i++) {
    char c = string_get(self)[i];

    if((c > 47 && c < 58) || (c > 64 && c < 91) ||
       (c > 96 && c != 95 && c < 123)) {
      string_add_char(output, c);
    } else if(c == 32) {
      string_add_char(output, '_');
    } else {
      if(i == 0) {
        add_underscore = 1;
      }
      snprintf(buf, 2, "%02x", c & 0xff);
      string_add_str(output, buf);
    }
  }

  if(add_underscore) {
    ret_value = string_new("_");
  } else {
    ret_value = string_new("");
  }
  string_add_str(ret_value, string_get(output));

  return string_get(ret_value);
}

EmeraldsString *string_remove_underscores(EmeraldsString *self) {
  EmeraldsString *self_dup = string_new("");

  char *self_str = string_get(self);
  for(size_t i = 0; i < string_size(self); i++) {
    if(self_str[i] != '_') {
      string_add_char(self_dup, self_str[i]);
    }
  }

  return self_dup;
}

void string_free(EmeraldsString *self) {
  if(self != NULL && self->str != NULL) {
    free(self->str);
  }
  if(self != NULL) {
    free(self);
  }
}
