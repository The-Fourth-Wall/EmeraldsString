#include "headers/string_dup.h"

string *string_dup(string *sb) {
    string *dup = NULL;
    
    if(sb == NULL) return NULL;

    dup = string_new("");
    string_add_str(dup, string_get(sb));

    return dup;
}
