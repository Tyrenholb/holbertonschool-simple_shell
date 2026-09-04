# holbertonschool-simple_shell

Simple Shell 0.1

The first version of the shell established the basic shell loop:

* Display a prompt in interactive mode
* Read a command from standard input
* Create a child process using fork
* Execute commands using execve
* Wait for the child process to finish
* Handle end-of-file (Ctrl+D)
* Display an error when a command cannot be executed

Simple Shell 0.2

The second version of the shell adds support for command lines with arguments.

* Read commands with arguments
* Split the command line into separate arguments
* Store the command and arguments in an argv array
* Pass the argv array to execve()

At this stage, commands had to be entered using their full path, such as /bin/ls.Command arguments, PATH searching and built-in commands were not yet supported.

Simple Shell 0.3
The third version added support for locating commands through the PATH environment variable:

* Search each directory listed in PATH
* Run commands without requiring their full path, such as ls
* Continue supporting explicit paths such as /bin/ls and ./program
* Check whether a command exists before creating a child process
* Avoid calling fork() when a command cannot be found
* Display a not found error and return status 127 for missing commands

At this stage, external commands can be executed with or without an explicit path. Shell built-in commands are not yet implemented.
