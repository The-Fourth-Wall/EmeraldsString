#include "../export/String.h"
#include "../libs/Vector/export/Vector.h"

void print_strings(string *element) {
    printf("%s\n", string_get(element));
}

void print_chars(char c) {
    printf("char: `%c`\n", c);
}

static void string_interpolation_test(void) {
    printf("TESTING STRING INTERPOLATION\n");
    char *str = "Hello World";
    char *num = "42";
    puts("Num: `", num, "` should be `42` and String: `", str, "` should be `Hello World`", "\n");
    puts("My num is: ", num, " and my string is: ", str, "\n");
}

static void string_iteration_test(void) {
    printf("TESTING STRING ITERATION\n");
    string *iter = string_new("oblivious");
    printf("Iteration of `o b l i v i o u s`\n");
    string_iterate(iter, (string_lambda)print_chars);
    printf("\n");
    string_free(iter);
}

static void add_format_test(void) {
    printf("TESTING STRING ADD FORMAT\n");
    string *format_buf = string_new("");
    string_addf(format_buf, "%d plus %d is %d, %s, (%g - %g = %g)", 1, 1, 1+1, "This is nice", 5.3, 1.1, 5.3-1.1);
    printf("%s\n\n", string_get(format_buf));
    string_free(format_buf);
}

static void string_split_test(void) {
    printf("TESTING STRING SPLIT\n");
    string *str_to_split = string_new("cut me in pieces");
	string *delimeter_to_use = string_new(" ");
	vector *list_of_tokens = string_split(str_to_split, delimeter_to_use);
	vector_map(list_of_tokens, (vector_lambda)print_strings);
    printf("ORIGINAL: %s\n", string_get(str_to_split));
    printf("\n");
    string_free(str_to_split);
    string_free(delimeter_to_use);
    vector_free(list_of_tokens);
}

static void string_equality_test(void) {
    printf("TESTING STRING EQUALITY\n");
    string *one = string_new("test");
    string *two = string_new("test");
    if(string_equals(one, two)) printf("strings `one(\"test\")` and `two(\"test\")` are equal\n\n");
    string_free(one);
    string_free(two);
}

static void string_litterbin_test(void) {
    printf("TESTING (LITTERBIN) -> STRING\n");
    string *strValue1 = string_new("test value 1");
    string *strValue2 = string_new("test value 2");
    string *strValue3 = string_new("test value 3");
    string *strValue4 = string_new("test value 4");
    string *strValue5 = string_new("test value 5");
    printf("BEFORE: %s, %s, %s, %s, %s\n", string_get(strValue1), string_get(strValue2), string_get(strValue3), string_get(strValue4), string_get(strValue5));
    string_free(strValue1);
    string_free(strValue2);
    string_free(strValue3);
    string_free(strValue4);
    string_free(strValue5);
}

int main(void) {
    string_interpolation_test();
    string_iteration_test();
    add_format_test();
    string_split_test();
    string_equality_test();
    string_litterbin_test();

    return 0;
}
