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

/*
* print_env - prints the current enviroment
*
* Return: Always 0
*/

int print_env(void)
{
	int count = 0;

	while (environ[count] != NULL)
	{
		printf("%s\n", environ[count]);
		count++;
	}
	return (0);
}
