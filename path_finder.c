#include "shell.h"

/**
 * search_path - searches PATH directories for a command
 * @command: command to search for
 * @path: PATH variable
 *
 * Return: full path of command, or NULL
 */
char *search_path(char *command, char *path)
{
	char *path_copy;
	char *path_token;
	char *file_path;
	int command_length;
	int directory_length;
	struct stat buffer;

	command_length = strlen(command);
	path_copy = malloc(strlen(path) + 1);
	if (path_copy == NULL)
		return (NULL);

	strcpy(path_copy, path);
	path_token = strtok(path_copy, ":");

	while (path_token != NULL)
	{
		directory_length = strlen(path_token);
		file_path = malloc(command_length + directory_length + 2);

		if (file_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}

		sprintf(file_path, "%s/%s", path_token, command);

		if (stat(file_path, &buffer) == 0)
		{
			free(path_copy);
			return (file_path);
		}

		free(file_path);
		path_token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}

/**
 * find_command - searches for a command in PATH
 * @command: command to search for
 *
 * Return: full path of command, or NULL
 */
char *find_command(char *command)
{
	char **env;
	char *path;
	char *command_path;
	struct stat buffer;

	if (strchr(command, '/') != NULL)
	{
		if (stat(command, &buffer) == 0)
		{
			command_path = malloc(strlen(command) + 1);

			if (command_path == NULL)
			return (NULL);

			strcpy(command_path, command);
			return (command_path);
		}
	return (NULL);
}

	env = environ;
	path = NULL;

	while (*env != NULL)
	{
		if (strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env + 5;
			break;
		}
		env++;
	}

	if (path == NULL)
		path = "/bin:/usr/bin";



	return (search_path(command, path));
}
