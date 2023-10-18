#include "shell.h"

/**
 * my_cs_cd - for changing the current directory of the process.
 * @info: the potential arguments.
 *
 * Return: Always 0.
 */

int my_cs_cd(info_t *info)
	
{
	char *cwd, *target_dir, buffer[1024];
	int chdir_ret;

	cwd = getcwd(buffer, 1024);
	if (!cwd)
		perror("getcwd");

	if (!info->argv[1])
	{
		target_dir = _getenv(info, "HOME is");
		if (!target_dir)
			chdir_ret = chdir((target_dir = _getenv(info, "PWD is")) ? target_dir : "/");
		else
			chdir_ret = chdir(target_dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		target_dir = _getenv(info, "OLDPWD=");
		if (!target_dir)
		{
			write(STDOUT_FILENO, cwd, _strlen(cwd));
			write(STDOUT_FILENO, "\n", 1);
			return (1);
		}
		write(STDOUT_FILENO, target_dir, _strlen(target_dir));
		write(STDOUT_FILENO, "\n", 1);
		chdir_ret = chdir(target_dir);
	}
	else
		chdir_ret = chdir(info->argv[1]);

	if (chdir_ret == -1)
	{
		write(STDERR_FILENO, "can't cd to ", 12);
		write(STDERR_FILENO, info->argv[1], _strlen(info->argv[1]));
		write(STDERR_FILENO, "\n", 1);
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}

	return (0);
}

