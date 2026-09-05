#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <signal.h>
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
int run_command(char **argv, char *line);
int process_command(char **argv, char *line, char *program, int line_number);
void shell_exit(char *line, char **argv, int last_status);
int print_env(void);
void handle_sigint(int signal_number);
int setup_signal(void);
#endif
