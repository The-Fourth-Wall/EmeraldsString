#include "headers/string_split.h"

vector *string_split(string *str, string *delimeter) {
	size_t i;
	vector *str_tokens = vector_new();
	string *token_str = string_new("");

	/* Iterate through the chars constructing a string and
		reseting the value once we find the delimeter */
	for(i = 0; (i <= string_length(str)
	&& string_get_char_at_index(str, i) != '\0'); i++) {
		if(string_get_char_at_index(str, i) == string_get(delimeter)[0]) {
			/* We found a character matching the delimeter */
			vector_add(str_tokens, token_str);

			/* Reset the temp string */
			token_str = string_new("");
			continue;
		}

		string_add_char(token_str, string_get_char_at_index(str, i));
	}

	/* We add the last collected characters */
	vector_add(str_tokens, token_str);
	return str_tokens;
}
