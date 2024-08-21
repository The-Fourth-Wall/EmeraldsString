#include "../src/EmeraldsString.h" /* IWYU pragma: keep */

#include <stdio.h>

void *print_strings(char *element) {
  printf("%s\n", element);
  return element;
}

void *free_strings(char *element) {
  string_free(element);
  return element;
}

char print_chars(char c) {
  printf("char: `%c`\n", c);
  return c;
}

/*
static void string_interpolation_test(void) {
  char *str = "Hello World";
  char *num = "42";
  printf("TESTING STRING INTERPOLATION\n");
  string_puts(
    "Num: `",
    num,
    "` should be `42` and String: `",
    str,
    "` should be `Hello World`",
    "\n"
  );
  string_puts("My num is: ", num, " and my string is: ", str, "\n");
}
*/

static void string_iteration_test(void) {
  char *iter = string_new("oblivious");
  printf("TESTING STRING ITERATION\n");
  printf("Iteration of `o b l i v i o u s`\n");
  string_iterate(iter, (EmeraldsStringLambda)print_chars);
  printf("\n");
  string_free(iter);
}

static void add_format_test(void) {
  char *format_buf = string_new("");
  printf("TESTING STRING ADD FORMAT\n");
  string_addf(
    format_buf,
    "%d plus %d is %d, %s, (%g - %g = %g)",
    1,
    1,
    1 + 1,
    "This is nice",
    5.3,
    1.1,
    5.3 - 1.1
  );
  printf("%s\n\n", format_buf);
  string_free(format_buf);
}

static void string_split_test(void) {
  const char delimeter_to_use = ' ';
  char *str_to_split          = string_new("cut me in pieces");
  char **list_of_tokens       = string_split(str_to_split, delimeter_to_use);
  printf("TESTING STRING SPLIT\n");
  vector_map(list_of_tokens, list_of_tokens, print_strings);
  printf("ORIGINAL: %s\n", str_to_split);
  printf("\n");
  vector_map(list_of_tokens, list_of_tokens, free_strings);
  string_free(str_to_split);
  vector_free(list_of_tokens);
}

static void string_equality_test(void) {
  char *one = string_new("test");
  char *two = string_new("test");
  printf("TESTING STRING EQUALITY\n");
  if(string_equals(one, two)) {
    printf("strings `one(\"test\")` and `two(\"test\")` are equal\n\n");
  }
  string_free(one);
  string_free(two);
}

static void string_litterbin_test(void) {
  char *strValue1 = string_new("test value 1");
  char *strValue2 = string_new("test value 2");
  char *strValue3 = string_new("test value 3");
  char *strValue4 = string_new("test value 4");
  char *strValue5 = string_new("test value 5");
  printf("TESTING (LITTERBIN) -> STRING\n");
  printf(
    "BEFORE: %s, %s, %s, %s, %s\n",
    strValue1,
    strValue2,
    strValue3,
    strValue4,
    strValue5
  );
  string_free(strValue1);
  string_free(strValue2);
  string_free(strValue3);
  string_free(strValue4);
  string_free(strValue5);
}

int main(void) {
  /* string_interpolation_test(); */
  string_iteration_test();
  add_format_test();
  string_split_test();
  string_equality_test();
  string_litterbin_test();

  return 0;
}
