#include "main.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of string
 * @env: to get enviroment
 * Return: alwayd int
*/

int main(int argc, char *argv[], char *env[])
{
	int pipe = 1, bytes, err_count = 1;
	const char *del = " ";
	size_t n_buffer = 0;
	char *dollar = "$ ", *buffer = NULL, command[50], *args[20], *only_command;
	if (argc != 1)
		_printf("%s: 0: Can't open %s\n", argv[0], argv[1]), exit(1);	
	if (isatty(STDIN_FILENO) == 0)
		non_interactive(argc, argv, env, &pipe);
	while (pipe)
	{
		write(1, dollar, 2);
		bytes = _getline(&buffer, &n_buffer, stdin);
		if (bytes == -1)
			free(buffer), exit(1);
		if (buffer[bytes - 1] == '\n')
			buffer[bytes - 1] = '\0';
		trim_buffer(buffer);
		if (_strcmp(buffer, "exit") == 0)
			free(buffer), exit(0);
		if (_strcmp(buffer, "env") == 0)
			_env(env);
		only_command = take_only_cmd(buffer);
		if (*buffer)
		{
			_tokenize(buffer, args, del, command, env);
			if (access(command, X_OK) == 0)
				_fork(argc, argv, buffer, args, only_command);
			else
				_printf("%s: %d: %s: not found\n",
						 argv[argc - 1], err_count++, only_command);
		}
		free(only_command);
	}
	return (0);
}
