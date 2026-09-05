# holbertonschool-simple_shell

This project is a basic UNIX command-line interpreter written in C. It reads
commands from standard input, separates them into arguments, runs built-in or
external commands, and returns the status of the last command.

The shell supports both interactive and non-interactive input.

## Compilation

Compile all source files from the root of the repository:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

This creates an executable named `hsh`.

## Usage

The shell supports both interactive and non-interactive use.

### Interactive Mode

Start the shell by running:

```bash
./hsh
```

When standard input is connected to a terminal, the shell displays its prompt:

```text
shell$
```

Commands can then be entered one at a time:

```text
shell$ ls -l
shell$ /bin/pwd
shell$ env
shell$ exit
```

Enter `exit` to close the shell. Pressing `Ctrl+D` at an empty prompt causes
`getline()` to encounter end-of-file, which closes the shell.

### Non-Interactive Mode

In non-interactive mode, commands are supplied through standard input instead
of being typed at the shell prompt.

A single command can be piped into the shell:

```bash
echo "ls -l /tmp" | ./hsh
```

Several commands can be supplied with `printf()`:

```bash
printf "pwd\nls -l\nenv\n" | ./hsh
```

Each newline represents a separate command. The shell reads and executes the
commands one at a time until it reaches end-of-file.

Input can also be redirected from a file:

```bash
./hsh < commands.txt
```

When the shell is running non-interactively, it does not display `shell$ `.
Command output and error messages are still written normally.

After reaching end-of-file, the shell exits with the status returned by the
last command. If a command cannot be found, its status is set to `127` and the
shell continues reading any remaining input lines.

## How Commands Are Processed

For every line of input, the shell:

1. Reads the line using `getline()`.
2. Removes the trailing newline.
3. Splits the line into tokens using spaces and tabs.
4. Stores the command in `argv[0]` and its arguments in the remaining positions.
5. Checks whether the command is a built-in.
6. Locates external commands using either a direct path or the `PATH`
   environment variable.
7. Creates a child process only after an external command has been found.
8. Executes the command with `execve()` and waits for it to finish.

For example:

```text
ls -l /tmp
```

is parsed as:

```text
argv[0] = "ls"
argv[1] = "-l"
argv[2] = "/tmp"
argv[3] = NULL
```

Because `ls` does not contain `/`, the shell searches for it in each directory
listed in `PATH`. The `/` in `/tmp` does not affect command lookup because
`/tmp` is an argument rather than `argv[0]`.

If the command name contains `/`, it is treated as a direct path instead:

```text
/bin/ls
./program
directory/program
```

Absolute paths begin from the root directory, such as `/bin/ls`. Relative paths
such as `./program` and `directory/program` are resolved from the current
directory.

If the command does not contain `/`, the shell finds `PATH` in `environ`, splits
it into directories, and combines each directory with the command name. When a
matching path is found, its full path is passed to `execve()`.

If no matching command is found, the shell:

- Displays a `not found` error
- Sets the command status to `127`
- Does not call `fork()`
- Continues reading the next input line

## Signal Handling

In interactive mode, the shell handles `SIGINT` (`Ctrl+C`) by printing a new
prompt instead of exiting. It installs this handler only when standard input is
connected to a terminal.

External commands retain their normal behaviour, so pressing `Ctrl+C` while
`/bin/sleep 20` is running stops the command and returns control to the shell.

## Development Stages

### Simple Shell 1.0

The current version added the `env` built-in command:

- Recognise `env` before performing PATH lookup
- Print each entry from the current environment
- Run the built-in directly without creating a child process

At this stage, the shell supports interactive and non-interactive input,
commands with arguments, PATH lookup, the `exit` and `env` built-ins, exit
statuses, and interactive `Ctrl+C` handling.

### Simple Shell 0.4

The fourth version added the `exit` built-in command:

- Recognise `exit` before performing PATH lookup
- Free the parsed argument array and input buffer before exiting
- Exit using the status returned by the last command

### Simple Shell 0.3

The third version added support for locating commands through the `PATH`
environment variable:

- Search each directory listed in `PATH`
- Run commands without requiring their full path, such as `ls`
- Continue supporting explicit paths such as `/bin/ls` and `./program`
- Check whether a command exists before creating a child process
- Avoid calling `fork()` when a command cannot be found
- Display a `not found` error and set status `127` for missing commands

At this stage, external commands could be executed with or without an explicit
path. Shell built-in commands were not yet implemented.

### Simple Shell 0.2

The second version added support for command lines with arguments:

- Read commands with arguments
- Split the command line into separate arguments
- Store the command and arguments in an `argv` array
- Pass the `argv` array to `execve()`

At this stage, commands still had to be entered using their full path, such as
`/bin/ls`. PATH searching and built-in commands were not yet supported.

### Simple Shell 0.1

The first version established the basic shell loop:

- Display a prompt in interactive mode
- Read a command from standard input
- Create a child process using `fork()`
- Execute commands using `execve()`
- Wait for the child process to finish
- Handle end-of-file (`Ctrl+D`)
- Display an error when a command cannot be executed
