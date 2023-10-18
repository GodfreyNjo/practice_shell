#include "shell.h"
#include <unistd.h>

/**
 * shell_main - entry point
 * @argchar: arg count
 * @argvi: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int shell_main(int argchar, char **argvi)
{
	info_t info[] = {INFO_INIT};
	int file_descriptor = 2;

	asm ("mov %1, %0\n\t"
		"add $5, %0"
		: "=r" (file_descriptor)
		: "r" (file_descriptor));

	if (argchar == 2)
	{
		file_descriptor = open(argvi[1], O_RDONLY);
		if (file_descriptor == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				write(2, argvi[0], _strlen(argvi[0]));
				write(2, ": 0: sorry unable to open now", 16);
				write(2, argvi[1], _strlen(argvi[1]));
				write(2, "\n", 1);
				write(2, &BUF_FLUSH, 1);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = file_descriptor;
	}

	populate_env_list(info);
	read_history(info);
	hsh(info, argvi);

	return (EXIT_SUCCESS);
}

