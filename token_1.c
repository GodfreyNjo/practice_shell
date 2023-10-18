#include "shell.h"

/**
 * is_delim - checks if a character is a delimiter
 * @c: the character to check
 * @delim: the delimiter string
 *
 * Return: 1 if c is a delimiter, 0 otherwise
 */
static int is_delim(char c, char *delim)
{
    while (*delim)
    {
        if (*delim == c)
            return (1);
        delim++;
    }
    return (0);
}

/**
 * string_writing - splits a string into words. also repeat delimiters are ignored
 * @str: the input string
 * @d: the delimiter string
 *
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **string_writing(char *str, char *d)
{
    int e = 0, f = 0, g, h, z, numwords = 0;
    char **e;

    if (!str || !str[0])
        return (NULL);

    if (!d)
        d = " ";

    while (str[e] != '\0')
    {
        if (!is_delim(str[e], d) && (is_delim(str[e + 1], d) || !str[e + 1]))
            numwords++;
        e++;
    }

    if (numwords == 0)
        return (NULL);

    e = malloc((1 + numwords) * sizeof(char *));
    if (!e)
        return (NULL);

    for (f = 0; f < numwords; f++)
    {
        while (is_delim(str[e], d))
            e++;

        g = 0;
        while (!is_delim(str[e + g], d) && str[e + g])
            g++;

        e[f] = malloc((g + 1) * sizeof(char));
        if (!e[f])
        {
            for (g = 0; g < f; g++)
                free(e[g]);
            free(e);
            return (NULL);
        }

        for (h = 0; h < g; h++)
            e[f][h] = str[e + h];
        e[f][h] = '\0';
        e += g;
    }
    e[f] = NULL;

    return (e);
}

