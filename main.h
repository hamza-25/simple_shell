#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <signal.h>

char *_strcpy(char *destin, const char *source);
void trim_buffer(char *buffer);
int main(int argc, char *argv[], char *env[]);
size_t _strlen(const char *str);
void _print(const char *str);
char *_strdup(const char *str);
void _fork(int argc, char *argv[], char *buf, char **ave, char *only);
int _strcmp(const char *string1, const char *string2);
void tok_buf(char *buf, char *args[], const char *del,
							char *str, char *env[]);
char *full_path(char *env[], char cmd[]);
void _printf(const char *format, ...);
void tostring(int num);
char *path_check(char path[]);
void _env(char *env[]);
void non_interactive(int argc, char *argv[], char *env[], int *pipe);
char *take_only_cmd(char **buffer, int *no_exc);
ssize_t _getline(char **line, size_t *n, FILE *stream);
void ls_check(char *ave[], char *buf, char *only);
void change_dir(char *buffer, char *cmd);
void comments(char **buf, int *no_exc);
void tok(char **buf, const char **del, char **token, char **str, char *args[]);
void handle_input_command(char **buffer, size_t *n_buffer, int *no_exc,
	char *env[], char **only_command);
void handle_sigint(int sig_num);

#endif
