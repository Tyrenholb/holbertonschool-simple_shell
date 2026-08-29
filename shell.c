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
	_exit(1);
}

/**
 * read_command - reads a command from standard input
 * @line: pointer to the command line
 * @size: size of the command buffer
 *
 * Return: number of characters read, or -1 on failure
 */
ssize_t read_command(char **line, size_t *size)
{
	ssize_t characters;

	if (isatty(STDIN_FILENO))
	{
		printf("shell$ ");
		fflush(stdout);
	}
	characters = getline(line, size, stdin);

	if (characters > 0 && (*line)[characters - 1] == '\n')
		(*line)[characters - 1] = '\0';
		return (characters);
}

/**
 * main - runs a basic UNIX command-line interpreter
 *
 * Return: 0 on success, 1 on failure
 */
int main(void)
{
	char *line = NULL;
	char *argv[2];
	int status;
	pid_t child_pid;
	ssize_t characters;
	size_t size = 0;

	while (1)
	{
		characters = read_command(&line, &size);
		if (characters == -1)
		{
			free(line);
			return (0);
		}
		argv[0] = strtok(line, " \t");

		if (argv[0] == NULL)
			continue;
		argv[1] = NULL;

		child_pid = fork();

		if (child_pid == -1)
		{
			perror("fork");
			free(line);
			return (1);
		}

		if (child_pid == 0)
		{
			execute_command(argv, line);
		}
		else
		{
			wait(&status);
		}
	}
}
