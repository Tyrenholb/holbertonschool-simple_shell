#include "shell.h"

/**
 * parse_command - separates a command line into arguments
 * @line: command line to parse
 *
 * Return: argument array, or NULL on allocation failure
 */

char **parse_command(char *line)
 {
	char **argv;
	char *token;
	size_t argv_capacity;
	size_t argv_count;

	argv_capacity = strlen(line) + 1;
	argv = malloc(sizeof(*argv) * argv_capacity);
	if (argv == NULL)
		return (NULL);

	argv_count = 0;
	token = strtok(line, " \t");

	while (token != NULL)
	{
		argv[argv_count] = token;
		argv_count++;
		token = strtok(NULL, " \t");
	}
	argv[argv_count] = NULL;

	return (argv);
 }
