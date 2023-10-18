#include "shell.h"

/**
 * my_env_disp - prints the current environment
 * @msg: Structure containing potential arguments.
 *
 * Return: Always 0
 */
int my_env_disp(messg_t *msg)
{
    list_t *current_node = msg->env;

    while (current_node)
    {
        write(1, current_node->str, _strlen(current_node->str));
        write(1, "\n", 1);
        current_node = current_node->next;
    }

    return 0;
}

/**
 * my_getenv - will get the value of env variable
 * @msg: Structure containing potential arguments.
 * @idty: the env var name
 *
 * Return: the value or NULL if not found
 */
char *my_getenv(messg_t *msg, const char *idty)
{
    list_t *current_node = msg->env;
    char *match;

    while (current_node)
    {
        match = starts_with(current_node->str, idty);
        if (match && *match)
            return match;
        current_node = current_node->next;
    }

    return NULL;
}

