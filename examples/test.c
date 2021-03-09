#include "../export/String.h"
#include "../libs/Vector/export/Vector.h"

void print_strings(string *element) {
    printf("%s\n", string_get(element));
}

void print_chars(char c) {
    printf("char: `%c`\n", c);
}

int main(void) {
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
    free(strValue1);
    free(strValue2);
    free(strValue3);
    free(strValue4);
    free(strValue5);
    printf("AFTER:  %p, %p, %p, %p, %p\n\n", string_get(strValue1), string_get(strValue2), string_get(strValue3), string_get(strValue4), string_get(strValue5));

    return 0;
}
