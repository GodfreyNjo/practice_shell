#include "shell.h"
#include <unistd.h>

/**
 * main_shell_loop - Main shell loop
 * @messg: Pointer to the message structure
 *
 * @argv: Argument vector from main()
 *
 * Return: 0 on success, 1 on error, or appropriate error code
 */

int main_shell_loop(messg_t *messg, char **argv)
{
    ssize_t read_status;
    int builtin_return;

    do
    {
        clear_messg(messg);

        if (interactive_mode(messg))
            write(STDOUT_FILENO, "$ ", 2);

        write(STDOUT_FILENO, BUF_FLUSH, 1);
        read_status = get_input(messg);

        if (read_status != -1)
        {
            set_messg(messg, argv);
            builtin_return = find_builtin(messg);

            if (builtin_return == -1)
                find_command(messg);
        }
        else if (interactive_mode(messg))
        {
            write(STDOUT_FILENO, "\n", 1);
        }

        free_messg(messg, 0);

    } while (read_status != -1 && builtin_return != -2);

    write_history(messg);
    free_messg(messg, 1);

    if (!interactive_mode(messg) && messg->status)
        exit(messg->status);

    if (builtin_return == -2)
    {
        if (messg->error_number == -1)
            exit(messg->status);
        exit(messg->error_number);
    }

    return (builtin_return);
}
