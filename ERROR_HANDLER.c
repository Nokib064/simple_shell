#include "shell.h"

/**
 * not_a - write error ("sh: 1: lss: not found")
 * @usr_inp: user's input command
 * @nput: nth input command
 * @env_llst: environmental variables linked list in shll
 */
void not_available(char *usr_inp, int nput, list_s *env_llst)
{
	int counter = 0;
	char *shell, *num;

	shell = _getenv("_", env_llst);
	while (shell[counter] != '\0')
		counter++;
	write(STDOUT_FILENO, shell, counter);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	num = int_to_str(nput);
	counter = 0;
	while (num[counter] != '\0')
		counter++;
	write(STDOUT_FILENO, num, counter);
	free(num);
	write(STDOUT_FILENO, ": ", 2);
	counter = 0;
	while (usr_inp[counter] != '\0')
		counter++;
	write(STDOUT_FILENO, usr_inp, counter);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "not available\n", 14);
}

#include "shell.h"
/**
 * unable_toCd - write error
 * @usr_inp: inputted argument after the cmd cd
 * @nput: nth user's input command
 * @env_llst: bring in environmental variables linked list
 */
void unable_toCd(char *usr_inp, int nput, list_s *env_llst)
{
	int counter = 0;
	char *shell, *num;

	shell = _getenv("_", env_llst);
	while (shell[counter] != '\0')
		counter++;
	write(STDOUT_FILENO, shell, counter);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	num = int_to_str(nput);
	counter = 0;
	while (num[counter] != '\0')
		counter++;
	write(STDOUT_FILENO, num, counter);
	free(num);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "cd: unable to cd to ", 20);
	counter = 0;
	while (usr_inp[counter] != '\0')
		counter++;

	write(STDOUT_FILENO, usr_inp, counter);
	write(STDOUT_FILENO, "\n", 1);
}

#include "shell.h"
/**
 * invalid_number - write error (invalid number)
 * @usr_inp: user input argument after the cmd exit
 * @nput: nth user input command
 * @env_llst: environmental variables linked list
 */
void invalid_number(char *usr_inp, int nput, list_s *env_llst)
{
	int counter = 0;
	char *shell = NULL, *num = NULL;

	shell = _getenv("_", env_llst);
	while (shell[counter] != '\0')
		counter++;
	write(STDOUT_FILENO, shell, counter);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	num = int_to_str(nput);

	for (counter = 0; usr_inp[counter] != '\0'; counter++)
		write(STDOUT_FILENO, num, counter);
	free(num);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "exit: Invalid number: ", 22);
	counter = 0;
	while (usr_inp[counter] != '\0')
		counter++;
	write(STDOUT_FILENO, usr_inp, counter);
	write(STDOUT_FILENO, "\n", 1);

}


#include "shell.h"
/**
 * int_to_str - converts an int to a string
 * @num: integer
 * Return: returns the int as a string. returns NULL if failed
 */

char *int_to_str(int num)
{
	int digit, tens, i = 0, j = 0, k;
	char *result;

	digit = num;
	tens = 1;

	if (num < 0)
		j = 1;
	result = malloc(sizeof(char) * (numlen(digit) + 2 + j));
	if (result == NULL)
		return (NULL);
	if (num < 0)
	{
		result[i] = '-';
		i++;
	}
	for (k = 0; digit > 9 || digit < -9; k++)
	{
		digit /= 10;
		tens *= 10;
	}
	for (digit = num; k >= 0; k--)
	{
		if (digit < 0)
		{
			result[i] = (digit / tens) * -1 + '0';
			i++;
		}
		else
		{
			result[i] = (digit / tens) + '0';
			i++;
		}
		digit %= tens;
		tens /= 10;
	}
	result[i] = '\0';
	return (result);
}

