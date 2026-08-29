#include <unistd.h>
#include <stdio.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
/*
int main(void)
{
    char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

    printf("Before execve\n");
    if (execve(argv[0], argv, NULL) == -1)
    {
        perror("Error:");
    }
    printf("After execve\n");
    return (0);
}*/

#include <stdio.h>
#include <unistd.h>

int main(void) {
    // 1. Properly quote the string literals
    char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

    // 2. Define a valid environment array to pass to execve
    char *envp[] = {NULL};

    printf("Before execve\n");

    // 3. Execute the binary with the arguments and environment
    if (execve(argv[0], argv, envp) == -1) {
        perror("Error");
    }

    // 4. This only runs if execve FAILS (e.g., file not found or permission denied)
    printf("After execve\n");
    return (0);
}
