#include "../export/String.h"
#include "../libs/Vector/export/Vector.h"

void print_strings(string *element) {
    printf("%s\n", string_get(element));
}

void print_chars(char c) {
    printf("char: `%c`\n", c);
}

int main(void) {
    char *format_buf_p = NULL;
    printf("TESTING STRING INTERPOLATION\n");
    char *str = "Hello World";
    char *num = "42";
    puts("Num: `", num, "` should be `42` and String: `", str, "` should be `Hello World`", "\n");
    puts("My num is: ", num, " and my string is: ", str, "\n");

    printf("TESTING STRING ITERATION\n");
    string *iter = string_new("oblivious");
    printf("Iteration of `o b l i v i o u s`\n");
    string_iterate(iter, (string_lambda)print_chars);
    printf("\n");
    printf("TESTING STRING SPLIT\n");
    string *str_to_split = string_new("cut me in pieces");
	string *delimeter_to_use = string_new(" ");

    printf("TESTING STRING ADD FORMAT\n");
    string *format_buf = string_new("");
    string_addf(format_buf, "%d plus %d is %d, %s, (%g - %g = %g)", 1, 1, 1+1, "This is nice", 5.3, 1.1, 5.3-1.1);
    printf("%s\n", (format_buf_p = string_get(format_buf)));
    free(format_buf_p);
	
	vector *list_of_tokens = string_split(str_to_split, delimeter_to_use);
	vector_map(list_of_tokens, (vector_lambda)print_strings);
    printf("ORIGINAL: %s\n", string_get(str_to_split));
    printf("\n");
    printf("TESTING STRING EQUALITY\n");
    string *one = string_new("test");
    string *two = string_new("test");
    if(string_equals(one, two)) printf("strings `one(\"test\")` and `two(\"test\")` are equal\n\n");

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
    printf("AFTER:  %p, %p, %p, %p, %p\n\n", (void*)string_get(strValue1), (void*)string_get(strValue2), (void*)string_get(strValue3), (void*)string_get(strValue4), (void*)string_get(strValue5));

    string_free(iter);
    string_free(str_to_split);
    string_free(delimeter_to_use);
    string_free(one);
    string_free(two);

    vector_free(list_of_tokens);
    return 0;
}
