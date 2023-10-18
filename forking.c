#include "shell.h"
void the_forking_func(messg_t *messg)
{
    pid_t child_pid;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Fork error:");
        return;
    }

    if (child_pid == 0)
    {
        if (execve(messg->path, messg->argv, get_environ(messg)) == -1)
        {
            perror("Execve error:");
            free_messg(messg, 1);
            exit(1);
        }
    }
    else
    {
        wait(&(messg->status));
        if (WIFEXITED(messg->status))
        {
            messg->status = WEXITSTATUS(messg->status);
            if (messg->status == 126)
            {
                char *perm_denied = "Permission is denied\n";
                write(STDERR_FILENO, perm_denied, _strlen(perm_denied));
            }
        }
    }
}

