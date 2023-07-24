#include "main.h"

/**
 * shell_split_line - shell_split_lines a string
 * @line: string to shell_split_line
 *  Return: pointer to an array of tokens
 */

char **shell_split_line(char *line)
{
	char **tokens = NULL;
	char *token = NULL;
	int i = 0, len = 0;

	len = _strlen(line);
	if (len == 0)
		return (NULL);
	tokens = malloc(sizeof(char *) * (len + 1));
	if (tokens == NULL)
	{
		perror("Fatal Error");
		return (NULL);
	}
	token = my_own_strtok(line, " \n\t\r");
	while (token != NULL)
	{
		tokens[i] = token;
		token = my_own_strtok(NULL, " \n\t\r");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}

