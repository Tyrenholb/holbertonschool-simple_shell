#include "shell.h"
/**
 * execute_command - executes a command
 * @argv: array containing the command
 * @line: command line to free
 *
 * Return: Nothing
 */
void execute_command(char **argv, char *line)
{
	execve(argv[0], argv, environ);
	perror("execve");
	free(line);
	free(argv);
	_exit(1);
}
