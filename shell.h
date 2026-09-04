#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

extern char **environ;

void execute_command(char **argv, char *line);
ssize_t read_command(char **line, size_t *size);
char **parse_command(char *line);
char *find_command(char *command);
char *search_path(char *command, char *path);
void run_command(char **argv, char *line);
int process_command(char **argv, char *line, char *program, int line_number);

#endif
