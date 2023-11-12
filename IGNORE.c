#include "shell.h"

/**
 * ignore_space - return string without spaces in front
 * @str: string
 * Return: new string
 */
char *ignore_space(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

/**
 * skipSpacesAndNewlines - skips leading spaces and newlines in a string
 * @str: input string
 * Return: updated string pointer after skipping spaces and newlines
 */
char *skipSpacesAndNewlines(char *str)
{
	while (*str == ' ' || *str == '\n')
		str++;

	return (str);
}


/**
 * ignore_delimet - returns a version of string without proceeding delims
 * @str: string
 * @delm: delimiter (e.g. " ")
 * Return: new string (e.g. "    ls -l" --> "ls -l")
 */
char *ignore_delimet(char *str, char delm)
{
	while (*str == delm)
		str++;
	return (str);
}
