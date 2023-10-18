#include "shell.h"

/**
 * freeing_idol_mem - frees a pointer
 * @ptr: address of the pointer to be  freed
 *
 * Return: 1 if freed, otherwise 0.
 */

int freeing_idol_mem(void **ptr)
{
    if (!ptr || !*ptr)
        return 0;

    free(*ptr);
    *ptr = NULL;
    return 1;
}

