#include "shell.h"

/**
 * checkIfInteractive - checks if the shell is in interactive mode
 * @info: struct containing shell information
 *
 * Return: 1 if in interactive mode, 0 otherwise
 */

int checking_If_Interactive(info_t *info)

{
	return (isTerminal && fileDescriptor <= 2);
}

