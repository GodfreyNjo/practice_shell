#include "shell.h"

/**
 * my_unset_alias - Unsets an alias.
 * @shell_info: Structure containing potential arguments.
 * @alias_str: The alias string.
 *
 * Return: Always 0 on success, 1 on error.
 */

int my_unset_alias(shell_info_t *shell_info, char *alias_str)

{
	char *equal_pos = _strchr(alias_str, '=');

	if (!equal_pos)
		return 1;

	char saved_char = *equal_pos;
	*equal_pos = 0;

	list_t *alias_list = &(shell_info->alias);
	char *node_starts_with_result = node_starts_with(shell_info->alias, alias_str, -1);
	int index_to_delete = get_node_index(shell_info->alias, node_starts_with_result);

	int return_val = delete_node_at_index(alias_list, index_to_delete);

	*equal_pos = saved_char;
	return return_val;
}

