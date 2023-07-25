#include "main.h"

/**
 * print_error - prints an error message
 * @argv0: name of the program
 * @command: command that failed
 * @error: error code
 */

void print_error(char *argv0, char *command, int error)
{
	char *error_str = NULL;

	write(STDERR_FILENO, argv0, _strlen(argv0));
	write(STDERR_FILENO, ": ", 2);
	error_str = _itoa(error);
	write(STDERR_FILENO, error_str, _strlen(error_str));
	free(error_str);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "not found\n", 10);
}

/**
 * execute - executes a command
 * @tokens: array of tokens
 * @argv: array of arguments
 * @env: array of environment variables
 * @line: line from getline
 * Return: 0 on success, 1 on failure
 */

int execute(char **tokens, char **argv, char **env, char *line)
{
	char *command = NULL;
	pid_t child_pid = 0;
	int status = 0;

	if (handle_builtins(tokens, argv, env, line) == 0)
	{
		get_last_exit(1, 0);
		return (0);
	}
	command = get_path(tokens[0]);
	if (command == NULL)
	{
		print_error(argv[0], tokens[0], 0);
		get_last_exit(1, 127);
		return (1);
	}
	if (!access(command, X_OK))
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror(argv[0]);
			free(command);
			return (1);
		}
		if (child_pid == 0)
		{
			if (execve(command, tokens, env) == -1)
			{
				perror(argv[0]);
				free(command);
				exit(1);
			}
		}
		else
		{
			free(command);
			wait(&status);
		}
		get_last_exit(1, 0);
	}
	return (status);
}

/**
 * get_last_exit - gets the last exit code
 * @action: 0 to get, 1 to set
 * @status: exit code
 * Return: last exit code
 */

int get_last_exit(int action, int status)
{
	static int last_exit;

	if (action == 1)
		last_exit = status;
	return (last_exit);
}
