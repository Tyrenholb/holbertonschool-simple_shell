#include "shell.h"
/**
 * shell_exit - free alloacted memory and exits the shell
 * @line input line buffer
 * @argv: parsed command argument array
 * @last_status: status of the last command
 *
 * return: Nothing
 */

void shell_exit(char *line, char **argv, int last_status)
{
	free(argv);
	free(line);
	exit(last_status);
}
