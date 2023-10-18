#include "shell.h"

/**
 * custom_str_concat - concatenates two strings with a length limitation
 * @home: the first string
 * @org: the second string
 * @longest: the maximum number of characters to concatenate.
 * Return: the concatenated string
 */

char *custom_str_concat(char *home, const char *org, int longest)
{
    char *result = home;
    int i = 0;

    while (*home)
        home++;

    while (*org && i < longest)
    {
        *home = *org;
        home++;
        org++;
        i++;
    }

    if (i < longest)
        *home = '\0';

    return result;
}

/**
 * custom_str_chr - locates a character in a string
 * @string: the string to be searched
 * @character: the character to find
 * Return: pointer to the first occurrence of character in string,
 *         or NULL if character is not found
 */
char *custom_str_chr(char *string, char character)
{
    while (*string)
    {
        if (*string == character)
            return string;
        string++;
    }

    return NULL;
}

