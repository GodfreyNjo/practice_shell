#include "shell.h"

/**
 * custom_string_copier - copies a string with length limitation
 * @home: the destination string to be copied to
 * @orgn: the source of the string
 * @long_: the maximum number of characters to copy
 * Return: the destination string
 */

char *custom_string_copier(char *home, const char *orgn, size_t long_)
{
    char *result = home;

    for (size_t i = 0; i < long_ && orgn[i] != '\0'; i++)
    {
        home[i] = orgn[i];
    }

    for (size_t i = strlen(orgn); i < long_; i++)
    {
        home[i] = '\0';
    }

    return result;
}

