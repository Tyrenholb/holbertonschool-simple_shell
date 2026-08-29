#include <stdio.h>
extern char **environ;
/**
 * main - compares env and environ
 *
 *  @env: environment pointer
 *
 * Return: Always 0
 */

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	printf("env is:     %p\n", (void *)env);
	printf("environ is: %p\n", (void *)environ);

return (0);
}
