#include "shell.h"
/**
 * not_available - displays an error message
 * @str: user's typed command
 * @n: nth user's typed command
 * @env: linked list of environmental variables to retrieve shell name
 */
void not_available(char *str, int n, list_s *env)
{
	int cmd_num;
	char *shell, *num;

	shell = get_env("_", env);
	for (cmd_num = 0; shell[cmd_num] != '\0'; cmd_num++)
	{
		write(STDOUT_FILENO, shell, cmd_num);
		free(shell);
		write(STDOUT_FILENO, ": ", 2);
		num = int_to_str(n);
	}

	for (cmd_num = 0; num[cmd_num] != '\0'; cmd_num++)
	{
		write(STDOUT_FILENO, num, cmd_num);
		free(num);
		write(STDOUT_FILENO, ": ", 2);
	}
	for (cmd_num = 0; str[cmd_num] != '\0'; cmd_num++)
	{
		write(STDOUT_FILENO, str, cmd_num);
		write(STDOUT_FILENO, ": ", 2);
		write(STDOUT_FILENO, "not available\n", 14);
	}
}
#include "shell.h"
/**
 * cd_to_impossible - writes an error message "can't cd to"
 * @str: user's typed argument after the 'cd' command
 * @n: nth user's typed command
 * @env: linked list of environmental variables to retrieve shell name
 */

void cd_to_impossible(char *str, int n, list_s *env)
{
	int cmd_num;
	char *shell, *num;

	shell = get_env("_", env);
	for (cmd_num = 0; shell[cmd_num] != '\0'; cmd_num++)
	{
		write(STDOUT_FILENO, shell, cmd_num);
		free(shell);
		write(STDOUT_FILENO, ": ", 2);
		num = int_to_str(n);
	}
	for (cmd_num = 0; num[cmd_num] != '\0'; cmd_num++)
	{
		write(STDOUT_FILENO, num, cmd_num);
		free(num);
		write(STDOUT_FILENO, ": ", 2);
		write(STDOUT_FILENO, "cd to impossible", 17);
	}
	for (cmd_num = 0; str[cmd_num] != '\0'; cmd_num++)
	{
		write(STDOUT_FILENO, str, cmd_num);
		write(STDOUT_FILENO, "\n", 1);
	}
}

#include "shell.h"

/**
 * illegal_num - displays  an error message
 * @str: user's typed argument after the 'exit' command
 * @n: nth user's typed command
 * @env: linked list of environmental variables to retrieve shell name
 */
void illegal_num(char *str, int n, list_s *env)
{
	int cmd_num;
	char *shell = NULL, *num = NULL;

	shell = get_env("_", env);
	for (cmd_num = 0; shell[cmd_num] != '\0'; cmd_num++)
	{
		write(STDOUT_FILENO, shell, cmd_num);
		free(shell);
		write(STDOUT_FILENO, ": ", 2);
		num = int_to_str(n);
	}
	for (cmd_num = 0; num[cmd_num] != '\0'; cmd_num++)
	{
		write(STDOUT_FILENO, num, cmd_num);
		free(num);
		write(STDOUT_FILENO, ": ", 2);
		write(STDOUT_FILENO, "unallowed number: ", 19);
	}
	cmd_num = 0;
	while (str[cmd_num] != '\0')
		cmd_num++;
	write(STDOUT_FILENO, str, cmd_num);
	write(STDOUT_FILENO, "\n", 1);
}
#include "shell.h"
/**
 * _memcpy - function that copies memory area
 * @dest: memory destination
 * @src: memory source
 * @n: mem bytes
 * Return: dest
 */
char *_memcpy(char *dest, char *src, int n)

{
	int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
