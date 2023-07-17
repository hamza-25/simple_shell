#include "main.h"
/**
 *
 *
 * const char *path
*/
void change_dir(char *buffer, char *cmd)
{
	char *token, *back = NULL, *now = NULL;

	now = getenv("PWD");
	back = getenv("OLDPWD");
	token = strtok(buffer, " ");
	token = strtok(NULL, " ");
	if (token == NULL) 
	{
        	if (chdir(getenv("HOME")) != 0)
            		perror("cd"), free(buffer), free(cmd), exit(1);
        	setenv("OLDPWD", now, 1);
    	} 
	else if (_strcmp(token, "-") == 0)
       	{
       		 if (back == NULL)
            		write(2, "cd: OLDPWD not set\n", _strlen("cd: OLDPWD not set\n"));
        	if (chdir(back) != 0)
			perror("cd"), free(buffer), free(cmd), exit(1);
        	setenv("OLDPWD", now, 1);
        	_printf("%s\n", back);
	}
	else
	{

		if (chdir(token) != 0)
            		_printf("-bash: %s: %s: No such file or directory\n", cmd, token), free(buffer), free(cmd);
        	setenv("OLDPWD", now, 1);
	}
}
