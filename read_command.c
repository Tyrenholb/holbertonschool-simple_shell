#include "shell.h"
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
