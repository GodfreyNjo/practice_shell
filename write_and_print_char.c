#include "shell.h"
#include <unistd.h>
#define WRITE_BUF_SIZE 1024


/**
 * _write_str - writes the character c to given file annotator
 * @c: The character to write
 * @file_annotator: The file annotator to write to
 *
 * Return: On success 1.
 * On error, -1 is returned then is error is set.
 */

int _write_str(char c, int file_annotator)
{
    static int i;
    static char buf[WRITE_BUF_SIZE];

    if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
    {
        write(file_annotator, buf, i);
        i = 0;
    }

    if (c != BUF_FLUSH)
        buf[i++] = c;

    return (1);
}

/**
 * _write_string_file_annotator - will write an input string to a file annotator
 * @str: this is the string to be printed
 * @file_annotator: the file annotator to write to
 *
 * Return: the number of charts entered
 */

int _write_string_file_annotator(char *str, int file_annotator)
{
    int i = 0;

    if (!str)
        return (0);

    while (str[i])
    {
        _write_str(str[i], file_annotator);
        i++;
    }

    return (i);
}

