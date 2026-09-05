#include "shell.h"

/**
 * main - runs a basic UNIX command-line interpreter
 * @ac: number of shell arguments
 * @av: shell argument array
 *
 * Return: last command status, or 1 on allocation failure
 */
int main(int ac, char **av)
{
	char *line = NULL;
	char **argv;
	ssize_t characters;
	size_t size = 0;
	int line_number = 0;
	int last_status = 0;

	(void) ac;

	if (setup_signal() == -1)
		return (1);
	while (1)
	{
		characters = read_command(&line, &size);
		if (characters == -1)
			break;

		line_number++;
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
		if (strcmp(argv[0], "exit") == 0)
		{
			shell_exit(line, argv, last_status);
		}
		last_status = process_command(argv, line, av[0], line_number);
		free(argv);
	}
	free(line);
	return (last_status);
}
