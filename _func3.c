#include "main.h"

/**
 *
 *
 *
*/

char *take_only_cmd(char *buffer)
{
        int i = 0;
        char str_cmd[50], *cmd;

	if (_strlen(buffer) >= 50)
	{
		perror("command to long\n");
		free(buffer), exit(1);
	}
	while (buffer[i])
        {
                if (buffer[i] == ' ')
                        break;
                str_cmd[i] = buffer[i];
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
	/*if (_strcmp(cmd, "cd") == 0)
	{
		write(1, "cd Y", 4);
		buffer = NULL;
	}*/
	return (cmd);
}

/**
 *
 *
*/
ssize_t _getline(char **line, size_t *n, FILE *stream)
{

    size_t size_buffer = *n, total_byt_read = 0;
    ssize_t num_of_byt_reads;
    char one_byte, *new_size_ptr;

    if (line == NULL || n == NULL || stream == NULL)
        return -1;

    if (*line == NULL)
    {
        size_buffer = 128;
        *line = malloc(size_buffer);
        if (*line == NULL)
            return -1;
        *n = size_buffer;
    }

    while ((num_of_byt_reads = read(fileno(stream), &one_byte, 1)) > 0)
    {
        if (total_byt_read >= size_buffer - 1)
        {
            size_buffer += 128;
            new_size_ptr = realloc(*line, size_buffer);
            if (!new_size_ptr)
                return -1;
            *n = size_buffer;
            *line = new_size_ptr;
        }

        (*line)[total_byt_read++] = one_byte;

        if (one_byte == '\n')
            break;
    }

    if (total_byt_read == 0 && num_of_byt_reads <= 0)
        return -1;

    (*line)[total_byt_read] = '\0';

    return total_byt_read;
}
