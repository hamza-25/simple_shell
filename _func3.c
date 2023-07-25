#include "main.h"

/**
 * take_only_cmd - Extract the first command from a string
 * @buffer: Input string containing one or more commands
 * @no_exc: Number of commands
 *
 * Return: Pointer to the first command
 */
char *take_only_cmd(char **buffer, int *no_exc , int argc, char *argv[], int *n_err)
{
	int i = 0;
	char str_cmd[50], *cmd;

	if (_strlen(*buffer) >= 50)
	{
		perror("command to long\n");
		free(*buffer), exit(1);
	}
	while ((*buffer)[i])
	{
		if ((*buffer)[i] == ' ')
			break;
		str_cmd[i] = (*buffer)[i];
		i++;
	}
	str_cmd[i] = '\0';
	cmd = malloc(_strlen(str_cmd) + 1);
	if (!cmd)
	{
		perror("fail to allocate");
		exit(1);
	}
	strcpy(cmd, str_cmd);
	if (_strcmp(cmd, "cd") == 0)
	{
		*no_exc = 0;
		change_dir(*buffer, cmd, argc, argv, n_err);
	}
	return (cmd);
}

/**
 * ls_check - Check if the command is 'ls' and validate directories
 * @ave: Array of command-line arguments
 * @buf: Buffer for storing command-line input
 * @only: The name of the command
 */
void ls_check(char *ave[], char *buf, char *only)
{
	const char *dir_path = NULL;
	DIR *dir;
	int index = 1;

	if (_strcmp(only, "ls") == 0 || _strcmp(ave[0], "/usr/bin/ls") == 0 ||
		_strcmp(ave[0], "/bin/ls") == 0)
{
	while (ave[index])
	{
		if (ave[index][0] != '-')
		{
			dir_path = ave[index];
			dir = opendir(dir_path);
			if (!dir)
			{
				fprintf(stderr, "%s: cannot access '%s': No such file or directory\n",
				only, dir_path);
				if (ave[index + 1] == NULL)
					free(buf), free(only), exit(2);
			}
			if (dir)
				closedir(dir);
		}
		index++;
	}
}
}

/**
 * _getline - Read a line from a file stream
 * @line: Pointer to a pointer that will store the read line
 * @n: Pointer to the size of the buffer allocated for the line
 * @stream: File stream to read from
 *
 * Return: Number of bytes read
 */
ssize_t _getline(char **line, size_t *n, FILE *stream)
{
	size_t size_buffer = *n, total_byt_read = 0;
	ssize_t num_of_byt_reads;
	char one_byte, *new_size_ptr;

	if (line == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*line == NULL)
	{
		size_buffer = 128;
		*line = malloc(size_buffer);
		if (*line == NULL)
			return (-1);
		*n = size_buffer;
	}
	while ((num_of_byt_reads = read(fileno(stream), &one_byte, 1)) > 0)
	{
		if (total_byt_read >= size_buffer - 1)
		{
			size_buffer += 128;
			new_size_ptr = realloc(*line, size_buffer);
			if (!new_size_ptr)
				return (-1);
			*n = size_buffer;
			*line = new_size_ptr;
		}
		(*line)[total_byt_read++] = one_byte;
		if (one_byte == '\n')
			break;
	}

	if (total_byt_read == 0 && num_of_byt_reads <= 0)
	{
		return (-1);
	}

	(*line)[total_byt_read] = '\0';
	return (total_byt_read);
}

/**
 *
 *
*/

void shell_exit(int status)
{
        if (status == 512)
                exit(status / 256);
        exit(0);
}
