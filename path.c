#include "main.h"

/**
 * full_path - Get the full path of a command in the environment
 * @env: Array of strings containing environment variables
 * @cmd: String containing the command to search for in the environment
 *
 * Return: Pointer to the full path
 */
char *full_path(char *env[], char cmd[])
{
	char *path_env = NULL, *path_copy, *token, *result;
	char test_path[1024];
	int i;
	const char *delim = ":";

	/* Find PATH environment variable */
	for (i = 0; env[i]; i++)
	{
		if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T' && 
		    env[i][3] == 'H' && env[i][4] == '=')
		{
			path_env = env[i] + 5;
			break;
		}
	}
	
	if (!path_env)
		return (_strdup(cmd));

	path_copy = _strdup(path_env);
	if (!path_copy)
		return (_strdup(cmd));

	token = strtok(path_copy, delim);
	while (token)
	{
		size_t token_len;
		
		token_len = _strlen(token);
		
		_strcpy(test_path, token);
		if (token_len > 0 && test_path[token_len - 1] != '/')
		{
			test_path[token_len] = '/';
			test_path[token_len + 1] = '\0';
			token_len++;
		}
		
		_strcpy(test_path + token_len, cmd);
		
		if (access(test_path, X_OK) == 0)
		{
			result = _strdup(test_path);
			free(path_copy);
			return (result);
		}
		token = strtok(NULL, delim);
	}
	
	free(path_copy);
	return (_strdup(cmd));
}

/**
 * path_check - Check if a file exists in the specified paths
 * @path: String containing multiple paths separated by colons
 *
 * Return: Pointer to the first path
 */
char *path_check(char path[])
{
	char *token, *path_ex = NULL, final_path[256];
	char *path_copy;
	int i = 0;
	const char *delim = ":";

	path_copy = _strdup(path);
	if (!path_copy)
		return (NULL);
	
	token = strtok(path_copy, delim);
	while (token)
	{
		path_ex = token;
		if (access(path_ex, F_OK) != -1)
		{
			while (path_ex[i] != '\0')
			{
				final_path[i] = path_ex[i];
				i++;
			}
			final_path[i] = '\0';
			free(path_copy);
			_strcpy(path, final_path);
			return (path);
		}
		token = strtok(NULL, delim);
	}
	free(path_copy);
	if (path_ex)
		_strcpy(path, path_ex);
	return (path);
}
