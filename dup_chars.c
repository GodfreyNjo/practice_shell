#include "shell.h"

/**
 * unique_chars_extraction - extracts characters from a string.
 * @pathstr: the string to extract from.
 * @start_idx: starting index.
 *
 * @end_idx: ending index
 *
 * Return: pointer to new buffer
 */
char *unique_chars_extraction(char *pathstr, int start_idx, int end_idx)
{
    static char buf[1024];
    int z = 0;

    for (int i = start_idx; i < end_idx; i++)
    {
        if (pathstr[i] != ':')
        {
            buf[z] = pathstr[i];
            z++;
        }
    }
    buf[z] = 0;
    return (buf);
}

