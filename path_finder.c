#include "shell.h"

/**
 * get_full_path - finds the command in the PATH string
 * @msg: the message structure
 * @path_str: the PATH string.
 *
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found, otherwise NULL
 */

char *get_full_path(messg_t *msg, char *path_str, char *cmd)
{
    if (!path_str)
        return (NULL);

    if ((custom_strlen(cmd) > 2) && custom_starts_with(cmd, "./"))
    {
        if (lets_check_if_exctble(msg, cmd))
            return (cmd);
    }

    char *start = path_str;
    char *end = path_str;

    while (*end != '\0')
    {
        if (*end == ':' || *(end + 1) == '\0')
        {
            char *path = custom_strndup(start, end - start);
            if (!path)
                return (NULL);

            if (*path == '\0')
                custom_strcat(path, cmd);
            else
            {
                custom_strcat(path, "/");
                custom_strcat(path, cmd);
            }

            if (lets_check_if_exctble(msg, path))
            {
                return path;
            }

            custom_free(path);

            if (*(end + 1) != '\0')
                start = end + 1;
        }
        end++;
    }

    return (NULL);
}

