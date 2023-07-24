#include "main.h"


/**
 * _strcpy - copies a string
 * @dest: destination string
 * @src: source string
 * Return: pointer to the copied string
 */

char *_strcpy(char *dest, char *src)
{
	int index = 0;

	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return: pointer to the concatenated string
 */

char *_strcat(char *dest, char *src)
{
	int index, index_2;

	index = 0;
	index_2 = 0;
	while (dest[index] != '\0')
		index++;

	while (src[index_2] != '\0')
	{
		dest[index] = src[index_2];
		index_2++;
		index++;
	}

	dest[index] = '\0';

	return (dest);
}

/**
 * ffree - frees a double pointer
 * @ptr: double pointer to be freed
 * Return: void
 */

void ffree(char **ptr)
{
	int index = 0;

	if (ptr == NULL)
		return;

	while (ptr[index] != NULL)
	{
		free(ptr[index]);
		index++;
	}

	free(ptr);
}

/**
 * cut_string - cuts a string when # is encountered
 * @str: string to be cut
 */

void cut_string(char *str)
{
	int index = 0;

	while (str[index] != '\0')
	{
		if (str[index] == '#')
		{
			str[index] = '\0';
			return;
		}
		index++;
	}
}

/**
 * _itoa - converts an integer to a string
 * @num: integer to be converted
 * Return: pointer to the converted string
 */

char *_itoa(int num)
{
	int index = 0, index_2 = 0, index_3 = 0, l = 0, m = 0;
	char *str = NULL;

	if (num == 0)
	{
		str = malloc(sizeof(char) * 2);
		if (str == NULL)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (num < 0)
		l = 1;
	m = num;
	while (m != 0)
	{
		m /= 10;
		index++;
	}
	str = malloc(sizeof(char) * (index + 1 + l));
	if (str == NULL)
		return (NULL);
	if (l == 1)
		str[0] = '-';
	for (index_2 = index - 1 + l; index_2 >= l; index_2--)
	{
		index_3 = num % 10;
		if (index_3 < 0)
			index_3 *= -1;
		str[index_2] = index_3 + '0';
		num /= 10;
	}
	str[index + l] = '\0';
	return (str);
}
