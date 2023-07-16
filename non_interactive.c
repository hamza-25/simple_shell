#include "main.h"

/**
 * non_interactive - entry point to non interactive mode
 * @argc: number of arguments
 * @argv: array of string
 * @env: to get enviroment
 * @pipe: its take 1 but with non interactive mode we hange it to 0
 * Return: alwayd int
*/

void non_interactive(int argc, char *argv[], char *env[], int *pipe)
{
	int bytes, err_count = 1;
	const char *del = " ";
	size_t n_buffer = 0;	
	char *buffer = NULL, command[50], *args[20], *only_command;
	*pipe = 0;
	while ((bytes = getline(&buffer, &n_buffer, stdin)) != -1)
	{
		trim_buffer(buffer);
		if(_strcmp(buffer, "exit") == 0)
			free(buffer), exit(0);
		only_command = take_only_cmd(buffer);
		if(*buffer)
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
	free(buffer);
}
