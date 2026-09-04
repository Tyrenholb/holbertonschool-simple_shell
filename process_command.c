#include "shell.h"

/**
 * process_command - finds and executes a command
 * @argv: command argument array
 * @line: input line
 * @program: shell invocation name
 * @line_number: current input line number
 *
 * Return: command exit status, or 127 if the command is not found
 */
int process_command(char **argv, char *line, char *program, int line_number)
{
	char *command_path;
	int command_status;

	if(strcmp(argv[0], "env") == 0)
		return (print_env());

	command_path = find_command(argv[0]);
	if (command_path == NULL)
	{
		fprintf(stderr, "%s: %d: %s: not found\n",
			program, line_number, argv[0]);
		return (127);
	}

	argv[0] = command_path;
	command_status = run_command(argv, line);
	free(command_path);

	return (command_status);
}
