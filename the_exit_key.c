#include "shell.h"
#include <unistd.h>

/**
 * my_exit_key - Exits the shell with a given exit status.
 * @info: Structure containing potential arguments.
 *
 * Return:
 *   - Returns 0 if info->argv[0] != "exit".
 *   - Returns 1 if there was an error parsing the exit argument.
 */
int my_exit_key(info_t *info)
{
    int exit_status = 0;

    if (!info->argv[1])
    {
        info->err_num = -1;
        return -2;
    }

    for (int i = 0; info->argv[1][i]; i++)
    {
        if (info->argv[1][i] < '0' || info->argv[1][i] > '9')
        {
            info->status = 2;
            write(STDERR_FILENO, " a disallowed digit(s): ", 16);
            write(STDERR_FILENO, info->argv[1], _strlen(info->argv[1]));
            write(STDERR_FILENO, "\n", 1);
            return (1);
        }
        exit_status = exit_status * 10 + (info->argv[1][i] - '0');
    }

    info->err_num = exit_status;
    return -2;
}

