#include "shell.h"

/**
 * write_alias - Prints an alias string.
 * @node: The alias node.
 *
 * Return: Always 0 on success, 1 on error.
 */
int write_alias(list_t *node)
{
	if (node)
	{
		char *equal_sign_pos = _strchr(node->str, '=');

		if (equal_sign_pos)
		{
			for (char *char_ptr = node->str; char_ptr <= equal_sign_pos; char_ptr++)
			{
				write(1, char_ptr, 1); // Use write to print characters individually
			}

			write(1, "\'", 1);
			write(1, equal_sign_pos + 1, _strlen(equal_sign_pos + 1));
			write(1, "\'\n", 2);

			return (0);
		}
	}

	return (1);
}

