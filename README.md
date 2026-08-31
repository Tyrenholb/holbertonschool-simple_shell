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

At this stage, commands had to be entered using their full path, such as /bin/ls.Command arguments, PATH searching and built-in commands were not yet supported.
