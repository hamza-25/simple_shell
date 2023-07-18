#include "main.h"

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
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("Failed to fork");
		free(buf);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		ls_check(ave, buf, only);
		execve(ave[0], ave, NULL);
		free(buf);
		free(only);
		exit(EXIT_FAILURE);
	}
	else
		wait(&status);
}
