#include "main.h"

/**
 * change_dir - Changes the current working directory
 *
 * @buffer: The input command buffer
 * @cmd: The command name
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
		_printf("-bash: %s: %s: No such file or directory\n", cmd, token);
	/*free(buffer), free(cmd);*/
	setenv("OLDPWD", now, 1);
	}
}

/**
 *
 *
*/

void comments(char **buf, int *no_exc)
{
        char *test;
        int i = 0;

        test = *buf;
        while (test[i])
        {
                if (test[0] == '#')
                {
                        *no_exc = 0;
                        break;
                }
                else if (test[i] == '#' && test[i -1] == ' ')
                {
                        *(*buf + i) = '\0';
                        break;
                }
                i++;
        }
}
