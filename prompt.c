#include "main.h"

/**
 * print_prompt - Prints the shell prompt with current working directory
 */
void print_prompt(void)
{
	char cwd[1024];
	char *home, *display_path;
	
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		home = getenv("HOME");
		if (home && _strcmp(cwd, home) == 0)
		{
			display_path = "~";
		}
		else if (home && strstr(cwd, home) == cwd)
		{
			/* If current directory is subdirectory of home, show relative path */
			display_path = cwd + _strlen(home);
			if (*display_path == '/')
				display_path++;
			if (*display_path == '\0')
				display_path = "~";
			else
			{
				static char temp_path[1024];
				temp_path[0] = '~';
				temp_path[1] = '/';
				_strcpy(temp_path + 2, display_path);
				display_path = temp_path;
			}
		}
		else
		{
			display_path = cwd;
		}
		
		_printf("%s$ ", display_path);
	}
	else
	{
		write(1, "$ ", 2);
	}
}

/**
 * update_pwd_env - Updates PWD environment variable
 */
void update_pwd_env(void)
{
	char cwd[1024];
	
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		setenv("PWD", cwd, 1);
	}
}