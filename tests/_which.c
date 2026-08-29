#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * find_path - Finds PATH in the environment
 * @env: Array of environment variables
 *
 * Return: Pointer to PATH's value, or NULL if not found
 */
char *find_path(char **env)
{
	int i;

	i = 0;
	while (env[i] != NULL)
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

/**
 * search_file - Searches for a file in each PATH directory
 * @path: Value of the PATH environment variable
 * @filename: Name of the file to find
 *
 * Return: 0 on success, 1 if memory allocation fails
 */
int search_file(char *path, char *filename)
{
	char *path_copy;
	char *directory;
	char *full_path;
	char *separator;
	struct stat st;

	path_copy = malloc(strlen(path) + 1);
	if (path_copy == NULL)
		return (1);
	strcpy(path_copy, path);

	directory = strtok(path_copy, ":");
	while (directory != NULL)
	{
		separator = "/";
		if (directory[strlen(directory) - 1] == '/')
			separator = "";

		full_path = malloc(strlen(directory) + strlen(filename) + 2);
		if (full_path == NULL)
		{
			free(path_copy);
			return (1);
		}
		sprintf(full_path, "%s%s%s", directory, separator, filename);

		if (stat(full_path, &st) == 0)
			printf("%s\n", full_path);

		free(full_path);
		directory = strtok(NULL, ":");
	}
	free(path_copy);
	return (0);
}

/**
 * main - Finds files in the current PATH
 * @ac: Argument count
 * @av: Argument vector
 * @env: Environment variables
 *
 * Return: 0 on success, 1 on failure
 */
int main(int ac, char **av, char **env)
{
	char *path;
	int i;

	if (ac < 2)
	{
		printf("Usage: %s filename ...\n", av[0]);
		return (1);
	}

	path = find_path(env);
	if (path == NULL)
	{
		printf("PATH not found\n");
		return (1);
	}

	i = 1;
	while (av[i] != NULL)
	{
		if (search_file(path, av[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
