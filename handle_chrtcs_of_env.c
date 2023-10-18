#include "shell.h"

#define ARGUMENT_ERROR_MESSAGE "Incorrect number of arguments\n"
#define TOO_FEW_ARGUMENTS_ERROR "Too few arguments.\n"

/**
 * the_env_set_ok - Initialize a new environment variable,
 *                  or modify an existing one
 * @msg: Structure containing potential arguments.
 *
 * Return: Always 0
 */
int the_env_set_ok(messg_t *msg)
{
    if (msg->argc != 3)
    {
        write(2, ARGUMENT_ERROR_MESSAGE, sizeof(ARGUMENT_ERROR_MESSAGE) - 1);
        return (1);
    }

    if (_setenv(msg, msg->argv[1], msg->argv[2]))
        return (0);

    return (1);
}

/**
 * the_env_unset_ok - Remove an env variable
 * @msg: Structure containing potential arguments.
 *
 * Return: Always 0
 */
int the_env_unset_ok(messg_t *msg)
{
    int i;

    if (msg->argc == 1)
    {
        write(2, TOO_FEW_ARGUMENTS_ERROR, sizeof(TOO_FEW_ARGUMENTS_ERROR) - 1);
        return (1);
    }

    for (i = 1; msg->argv[i]; i++)
    unset_environment_variable(msg, msg->argv[i]);

	    return (0);
}

/**
 * handle_env_popltn - populates env linked list
 * @msg: the structure containing potential arguments.
 *
 * Return: Always 0
 */
int handle_env_popltn(messg_t *msg)
{
    list_t *node = NULL;
    size_t i;

    for (i = 0; environ[i]; i++)
    {
        char *env_var = strdup(environ[i]);
        if (env_var == NULL)
        {
            free_env_list(node);
            return -1;
        }
        add_node_end(&node, env_var, 0);
    }

    msg->env = node;
    return 0;
}


