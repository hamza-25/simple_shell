#include "main.h"

/**
 * _env - Print environment variables
 * @env: Array of environment variables
 *
 * This function prints each element in the `env` array, which represents the
 * environment variables of the program. The elements are printed on separate
 * lines.
 */
void _env(char *env[])
{
	int i = 0, j;

	for (i = 0; env[i] != NULL; i++)
	{
		j = 0;
		while (env[i][j] != '\0')
			j++;
		/*
		 * write(STDOUT_FILENO, env[i], j);
		 * write(STDOUT_FILENO, "\n", 1);
		 */
		_printf("%s\n", env[i]);
	}
}
