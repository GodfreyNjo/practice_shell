#include "shell.h"

/**
 * split_string - splits a typical string into words
 * @input_string: the input string
 * @delimiter: the delimiter
 *
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **split_string(char *input_string, char delimiter)
{
    int i, j, k, numbrwords = 0;
    char **strings;

    if (input_string == NULL || input_string[0] == '\0')
        return (NULL);

    for (i = 0; input_string[i]; i++)
    {
        if (input_string[i] != delimiter)
        {
            numbrwords++;
            while (input_string[i] && input_string[i] != delimiter)
                i++;
        }
    }

    if (numbrwords == 0)
        return (NULL);

    strings = malloc((numbrwords + 1) * sizeof(char *));
    if (!strings)
        return (NULL);

    for (i = 0, j = 0; j < numbrwords; j++)
    {
        while (input_string[i] == delimiter)
            i++;

        k = 0;
        while (input_string[i + k] && input_string[i + k] != delimiter)
            k++;

        strings[j] = malloc((k + 1) * sizeof(char));
        if (!strings[j])
        {
            for (k = 0; k < j; k++)
                free(strings[k]);
            free(strings);
            return (NULL);
        }

        for (k = 0; input_string[i] && input_string[i] != delimiter; i++, k++)
            strings[j][k] = input_string[i];
        strings[j][k] = '\0';
    }
    strings[j] = NULL;

    return (strings);
}

