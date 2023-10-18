#include "shell.h"

/**
 * find_cmd_in_path - finds a command in PATH
 * @messg: the parameter & return message struct
 *
 * Return: void
 */
void find_cmd_in_path(messg_t *messg)
{
    char *path = NULL;
    int m = 0, n = 0;

    messg->path = messg->argv[0];
    if (messg->linecount_flag == 1)
    {
        messg->line_count++;
        messg->linecount_flag = 0;
    }
    while (messg->arg[m])
    {
        if (!is_delim(messg->arg[m], " \t\n"))
            n++;
        m++;
    }
    if (!n)
        return;

    path = find_path(messg, _getenv(messg, "PATH="), messg->argv[0]);
    if (path)
    {
        messg->path = path;
        fork_cmd(messg);
    }
    else
    {
        if ((interactive(messg) || _getenv(messg, "PATH=")
            || messg->argv[0][0] == '/') && is_cmd(messg, messg->argv[0]))
            fork_cmd(messg);
        else if (*(messg->arg) != '\n')
        {
            messg->status = 127;
            write(2, "command cannot be found\n", 10);
        }
    }
}

