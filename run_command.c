#include "shell.h"

/**
 * run_command - creates a child process and executes a command
 * @argv: array containing the command
 * @line: command line to free
 *
 * Return: Nothing
 */
void run_command(char **argv, char *line)
{
	int status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		free(argv);
		free(line);
		exit(1);
	}

	if (child_pid == 0)
		execute_command(argv, line);

	wait(&status);
}