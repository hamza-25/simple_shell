#include "main.h"
#include <dirent.h>

/**
* _fork - Forks a child process and executes a command in it
* @argc: The argument count
* @argv: The argument vector
* @buf: The command buffer
* @ave: The argument vector for execve
* @only: The command to execute
*/
void _fork(int argc, char *argv[], char *buf, char *ave[], char *only)
{
	signed int pid;
	int status, index = 1;
	const char *dir_path = NULL;
	DIR *dir;

	pid = fork();
	if (pid == -1)
	{
		perror("Failed to fork");
		free(buf);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (_strcmp(only, "ls") == 0 || _strcmp(ave[0], "/usr/bin/ls") == 0
				|| _strcmp(ave[0], "/bin/ls") == 0)
		{
			while (ave[index])
			{
				if (ave[index][0] != '-')
				{
					dir_path = ave[index];
					dir = opendir(dir_path);
					if (!dir)
					{
						_printf("%s: cannot access '%s': No such file or directory\n", only, dir_path);
						if (ave[index + 1] == NULL)
							free(buf), free(only), exit(1);
					}
					if (dir)
						closedir(dir);
				}
				index++;
			}
		}
		execve(ave[0], ave, NULL);
		free(buf);
		perror(argv[argc - 1]);
		exit(EXIT_FAILURE);
	}
	else
	wait(&status);
}
