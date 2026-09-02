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
	char *command_path;
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

		command_path = find_command(argv[0]);

		if (command_path != NULL)
		{
			argv[0] = command_path;
			run_command(argv, line);
			free(command_path);

		}
		free(argv);
	}
	free(line);
	return (0);
}
