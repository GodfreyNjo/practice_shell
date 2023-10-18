#include "shell.h"

/**
 * my_nov_alias - will emulate the alias builtin.
 * @shell_info: Structure containing potential arguments.
 *
 * Return: Always 0
 */
int my_nov_alias(shell_info_t *shell_info)
{
    int arg_index;
    char *equal_sign_pos;

    if (shell_info->argc == 1)
    {
        list_t *node = shell_info->alias;
        while (node)
        {
            simple_shell_print("%s\n", node->data);
            node = node->next;
        }
        return 0;
    }

    for (arg_index = 1; shell_info->argv[arg_index]; arg_index++)
    {
        equal_sign_pos = _strchr(shell_info->argv[arg_index], '=');
        if (equal_sign_pos)
            set_alias(shell_info, shell_info->argv[arg_index]);
        else
        {
            simple_shell_print("%s\n", node_starts_with(shell_info->alias, shell_info->argv[arg_index], '=')->data);
        }
    }

    return 0;
}

