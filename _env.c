#include "main.h"
/**
 * main - get enviroment variable
 * @argc: count args
 * @argv: array of args string
 * @env: get enviroment
 * Return: void
*/

void _env(char *env[])
{
	int i = 0, j;

	for (i = 0; env[i] != NULL; i++)
	{
		j = 0;
		while (env[i][j] != '\0')
			j++;
		/*write(STDOUT_FILENO, env[i], j);
		write(STDOUT_FILENO, "\n", 1);*/
		_printf("%s\n", env[i]);
	}
}
