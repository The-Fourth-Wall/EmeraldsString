#include "headers/string_functional_functions.h"

void string_iterate(string *sb, string_lambda apply) {
    char *sb_str = NULL;
    size_t i;

    if(sb == NULL || apply == NULL) return;

    sb_str = string_get(sb);

    for(i = 0; i < string_length(sb); i++)
        apply(sb_str[i]);
}

string *string_map(string *sb, string_lambda modifier) {
    char *sb_str = NULL;
    string *sb_dup = NULL;
    size_t i;
    
    if(sb == NULL || modifier == NULL) return NULL;

    sb_str = string_get(sb);
    sb_dup = string_new("");

    for(i = 0; i < string_length(sb); i++)
        string_add_char(sb_dup, modifier(sb_str[i]));

    return sb_dup;
}

string *string_filter(string *sb, string_lambda filter) {
    char *sb_str = NULL;
    string *sb_dup = NULL;
    size_t i;

    if(sb == NULL || filter == NULL) return NULL;

    sb_str = string_get(sb);
    sb_dup = string_new("");

    for(i = 0; i < string_length(sb); i++)
        if(filter(sb_str[i]))
            string_add_char(sb_dup, sb_str[i]);

    return sb_dup;
}
