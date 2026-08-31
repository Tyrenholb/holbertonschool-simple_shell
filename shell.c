#include "shell.h"
/**
 * main - runs a basic UNIX command-line interpreter
 *
 * Return: 0 on success, 1 on failure
 */
int main(void)
{
	char *line = NULL;
	char **argv;
	int status;
	pid_t child_pid;
	ssize_t characters;
	size_t size = 0;

	while (1)
	{
		characters = read_command(&line, &size);
		if (characters == -1)
		{
			break;
		}
		argv = parse_command(line);
		if (argv == NULL)
		{
			free(line);
			return (1);
		}
		if (argv[0] == NULL)
		{
			free(argv);
			continue;
		}
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			free(argv);
			free(line);
			return (1);
		}
		if (child_pid == 0)
			execute_command(argv, line);
		wait(&status);
		free(argv);
	}
	free(line);
	return (0);
}
