#ifndef __STRING_FUNCTIONAL_FUNCTIONS_H_
#define __STRING_FUNCTIONAL_FUNCTIONS_H_

#include "string_base.h"

/**
 * @func: string_lambda
 * @desc: A generic function type used upon iterable data structures
 * @param -> An element belonging to an iterable
 * @return -> A value that satisfies the callee's purpose (map, filter, reduce)
 **/
/* The param void* can have more than 1 argument stored as a list of some sort */
/* Since this is completely generic we can't check for validity of arguments */
/* The validity of the function is dependent on the callee */
typedef char (*string_lambda)(char);

/**
 * @func: string_iterate
 * @desc: Iterates through the characters of the string
 * @param sb -> The string builder we want to iterate
 * @param apply -> The function we apply to each character
 **/
void string_iterate(string *sb, string_lambda apply);

/**
 * @func: string_map
 * @desc: Maps each character of the string according to a modifier function
 * @param sb -> The string builder to map
 * @param modifier -> The string_lambda function to use for the conversions
 * @return A new mapped string
 **/
string *string_map(string *sb, string_lambda modifier);

/**
 * @func: string_filter
 * @desc: Filters out characters from the string according to a function
 * @param sb -> The string builder to filter
 * @param filter -> The labmda function to use
 * @return A new filtered string
 **/
string *string_filter(string *sb, string_lambda filter);

#endif
