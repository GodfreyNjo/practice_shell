#include "shell.h"
/**
 * lets_check_if_exctble - determines if a file is an executable command
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int lets_check_if_exctble(char *path)
{
    struct stat st;

    if (!path || stat(path, &st) != 0)
        return 0;

    if (st.st_mode & S_IFREG)
    {
        return 1;
    }
    return 0;
}
