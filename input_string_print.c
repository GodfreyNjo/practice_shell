#include "shell.h"
#include <unistd.h>

/**
 * _write_strng -writes an input string
 * @strng: the string to be written
 *
 * Return: NULL
 */
void _write_strng(char *strng)
{
    if (!strng)
        return;

    while (*strng)
    {
        write(1, strng, 1);
        strng++;
    }
}

