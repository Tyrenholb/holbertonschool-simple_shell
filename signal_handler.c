#include "shell.h"

/**
 * handle_sigint - Handles Ctrl + c at the shell prompt
 * @signal_number: Signal received
 */

void handle_sigint(int signal_number)
{
	(void)signal_number;
	write(STDOUT_FILENO, "\nshell$ ", 8);
}

/**
 * setup_signal - Sets the SIGINT handler in interactive mode
 *
 * Return: 0 on success, -1 on failure
 */

int setup_signal(void)
{
	if (isatty(STDERR_FILENO) && signal(SIGINT, handle_sigint) == SIG_ERR)
	{
		perror("signal");
		return (-1);
	}
	return (0);
}
