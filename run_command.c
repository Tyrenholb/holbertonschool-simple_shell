#include "shell.h"

/**
 * run_command - creates a child process and executes a command
 * @argv: array containing the command
 * @line: command line to free
 *
 * Return: child exit status, 128 plus signal number, or 1 on failure
 */
int run_command(char **argv, char *line)
{
	int status;
	pid_t child_pid;
	pid_t wait_result;


	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		free(argv);
		free(line);
		exit(1);
	}


	if (child_pid == 0)
		execute_command(argv, line);
	wait_result = wait(&status);
	if (wait_result == -1)
	{
		perror("wait");
		free(argv);
		free(line);
		exit(1);
	}
	if (WIFEXITED(status))
	{
		return (WEXITSTATUS(status));
	}
	if (WIFSIGNALED(status))
	{
		return (128 + WTERMSIG(status));
	}
	return (1);
}
