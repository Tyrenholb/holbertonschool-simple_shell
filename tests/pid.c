#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */

int main(void)
{
	pid_t my_pid;
	pid_t parent_pid;

	parent_pid = getppid();
	my_pid = getpid();
	printf("%u\n", my_pid);
	printf("%d\n",parent_pid);
	return (0);
}


