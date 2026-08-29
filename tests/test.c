#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
/**Write a program that executes the command
ls -l /tmp in 5 different child processes.
Each child should be created by
the same process (the father).
Wait for a child to exit before creating a new child.
*/

int main(void)
{
	pid_t child_pid;
	int status;
	int counter = 0;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	while (counter < 5)
	{
	child_pid = fork();
	if	(child_pid > 0)
	{
		wait(&status);
		counter++;
		printf("Count +1\n");

	}
	if	(child_pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
	{
		perror("execve");
		_exit(1);
	}
	}
	if (child_pid == -1)
	{
		printf("failed\n");
		return(0);
	}

}
return(0);
}