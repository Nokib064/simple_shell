#include "shell.h"
/**
 * int_to_str - convert an integer into a string
 * @arr_str: int
 * Return: returns the int as a string. returns NULL if failed
 */
char *int_to_str(int arr_str)
{
	int digits, tens, i = 0, t = 0, x;
	char *res;

	digits = arr_str;
	tens = 1;

	if (arr_str < 0)
		t = 1;
	res = malloc(sizeof(char) * (Digit_counts(digits) + 2 + t));
	if (res == NULL)
		return (NULL);
	if (arr_str < 0)
	{
		res[i] = '-';
		i++;
	}
	for (x = 0; digits > 9 || digits < -9; x++)
	{
		digits /= 10;
		tens *= 10;
	}
	for (digits = arr_str; x >= 0; x--)
	{
		if (digits < 0)
		{
			res[i] = (digits / tens) * -1 + '0';
			i++;
		}
		else
		{
			res[i] = (digits / tens) + '0';
			i++;
		}
		digits %= tens;
		tens /= 10;
	}
	res[i] = '\0';
	return (res);
}
#include "shell.h"
/**
 *_atoi- converta string to integer
 * @s : string to be converted
 * Return: 0 if no number in the string
 */
int _atoi(char *s)
{
	int i = 0;
	unsigned int result = 0;
	int sign = 1;

	if (s[0] == '-')
	{
		sign = -1;
		i = 1;
	}

	while (s[i] != '\0')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}

	return (result * sign);
}

#include "shell.h"
/**
 * t_strlen - returns the length of a token in a string
 * @str: the string containing the token
 * @pos: the index position of the token in the string
 * @delim: the delimiter used to separate tokens
 * Return: the length of the token
 */
int t_strlen(char *str, int pos, char delim)
{
	int len = 0;

	while (str[pos] != delim && str[pos] != '\0')
	{
		pos++;
		len++;
	}

	return (len);
}

#include "shell.h"
/**
 * t_size - returns the number of delimiters, ignoring continuous delimiters
 * @str: user's command typed into the shell
 * @delim: delimiter (e.g., " ")
 *
 * Return: number of delimiters (num_tokens = num_delimiters + 1)
 */
int t_size(char *str, char delim)
{
	int i = 0;
	int num_delimiters = 0;

	while (str[i] != '\0')
	{
		if (str[i] == delim && str[i + 1] != delim)
		{
			num_delimiters++;
		}
		i++;
	}

	return (num_delimiters);
}
#include "shell.h"
/**
 * Digit_counts - counts the number of digits in an integer
 * @i: integer
 * Return: number of digits
 */
int Digit_counts(int i)
{
	int count = 0;

	while (i != 0)
	{
		i /= 10;
		count++;
	}
	return (count);
}
