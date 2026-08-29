#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
extern char **environ;
/**
 * main - runs a basic UNIX command-line interpreter
 *
 * Return: 0 on success, 1 on failure
 */

int main(void)
{
	char *line = NULL;
	char *argv[2];
	int status;

	pid_t child_pid;
	ssize_t characters;
	size_t size = 0;

while (1)
{
	printf("shell$ ");
	fflush(stdout);

	characters = getline(&line, &size, stdin);
	if (characters == -1)
	{
		free(line);
		return(0);
	}
	line[characters -1] = '\0';

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		free(line);
		return(1);
	}
	if (child_pid == 0)
	{
		argv[0] = line;
		argv[1] = NULL;

		execve(argv[0], argv, environ);
		perror("execve");
		free(line);
		_exit(1);
	}
	else
	{
		wait(&status);
	}
	}
return(0);
}

