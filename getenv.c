#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern char **environ;
/**
 *
 *
 *
 *
 * Return: NULL
 */

char *_getenv(const char *name)
{
	int i;
	size_t length;

	if (name == NULL)
		return(NULL);
	length = strlen(name);

	i = 0;
	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, length) == 0 &&
		environ[i][length] == '=')
		{
			return (environ[i] + length +1);
		}
			i++;
	}
	return (NULL);
}

int main(int ac, char **av)
{
	char *value;

	if (ac != 2)
	{
		printf("Usage: %s variable_name ...\n", av[0]);
		return (1);
	}

	value = _getenv(av[1]);

	if (value == NULL)

		printf("%s not found\n", av[1]);
	else
		printf("%s=%s\n", av[1], value);


	return (0);
}
