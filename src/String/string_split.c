#include "headers/string_split.h"
#include "headers/string_dup.h"
#include <string.h> /* strtok */

vector *string_split(string *str, string *delimeter) {
	size_t i;
	vector *str_tokens = vector_new();
	string *dup = string_dup(str);
	char *token_ptr = string_get(dup);

	/* TODO -> IMPROVE SPEED */
	/* Iterate through the chars constructing a string and
		reseting the value once we find the delimeter */
	token_ptr = strtok(string_get(dup), string_get(delimeter));
	while(token_ptr != NULL) {
		vector_add(str_tokens, string_new(token_ptr));
		token_ptr = strtok(NULL, string_get(delimeter));
	}

	return str_tokens;
}
