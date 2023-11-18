#include "shell.h"
/**
 * t_size - returns number of delimeters
 * @usr_inp: user's input
 * @delimet: delimeter
 * Return: number of delimeters
 */
int t_size(char *usr_inp, char delimet)
{
	int i = 0, num_delim = 0;

	while (usr_inp[i] != '\0')
	{
		if ((usr_inp[i] == delimet) && (usr_inp[i + 1] != delimet))
		{
			num_delim++;
		}
		if ((usr_inp[i] == delimet) && (usr_inp[i + 1] == '\0'))
		{
			num_delim--;
		}
		i++;
	}
	return (num_delim);
}


#include "shell.h"
/**
 * ignore_delim - ignore delimiters
 * @str: string
 * @delimet: delimiter
 * Return: new string
 */
char *ignore_delim(char *str, char delimet)
{
	while (*str == delimet)
		str++;
	return (str);
}

#include "shell.h"
/**
 * _str_tok - tokenizes a string and returns an array of tokens
 * @user_inp: user input command
 * @delimet: delimeter (e.g. " ");
 * Return: an array of tokens (e.g. {"ls", "-l", "/tmp"}
 */
char **_str_tok(char *usr_inp, char *delimet)
{
	int buffs = 0, a = 0, j = 0, i = 0, len = 0, s = 0, t = 0;
	char **tok = NULL, chr;

	chr = delimet[0];
	usr_inp = ignore_delim(usr_inp, chr);
	buffs = t_size(usr_inp, chr);
	tok = malloc(sizeof(char *) * (buffs + 2));
	if (tok == NULL)
		return (NULL);
	while (usr_inp[s] != '\0')
		s++;
	while (j < s)
	{
		if (usr_inp[j] != chr)
		{
			len = t_strlen(usr_inp, j, chr);
			tok[a] = malloc(sizeof(char) * (len + 1));
			if (tok[a] == NULL)
				return (NULL);
			i = 0;
			while ((usr_inp[j] != chr) && (usr_inp[j] != '\0'))
			{
				tok[a][i] = usr_inp[j];
				i++;
				j++;
			}
			tok[a][i] = '\0';
			t++;
		}
		if (j < s && (usr_inp[j + 1] != chr && usr_inp[j + 1] != '\0'))
			a++;
		j++;
	}
	a++;
	tok[a] = NULL;
	return (tok);
}

#include "shell.h"

/**
 * _which - fleshes out command by appending it to a matching PATH directory
 * @usr_inp: first user command
 * @env_var: environmental variable
 * Return: a copy of fleshed out command
 */
char *_which(char *usr_inp, list_s *env_var)
{
	char *pth, *tem = NULL, **tok;
	int i = 0;

	pth = _getenv("PATH", env_var);
	tok = custom_strtok(pth, ":");
	free(pth);

	i = 0;
	while (tok[i] != NULL)
	{
		if (tok[i][0] == '\0')
			tem = getcwd(tem, 0);
		else
			tem = _strdup(tok[i]);
		tem = _strcat(tem, "/");
		tem = _strcat(tem, usr_inp);
		if (access(tem, F_OK) == 0)
		{

			db_ptr_free(tok);
			return (tem);
		}
		free(tem);
		i++;
	}
	db_ptr_free(tok);
	return (usr_inp);
}
#include "shell.h"
/**
 * custom_strtok - tokenizes a string (customized
 * @usr_inp: user input command
 * @delim: delimeter
 * Return: an array of tokens
 */
char **custom_strtok(char *usr_inp, char *delim)
{
	int buffs = 0, a = 0, j = 0, i = 0, len = 0, s = 0;
	char **tok = NULL, tem;

	tem = delim[0];
	buffs = custom_t_size(usr_inp, tem);
	tok = malloc(sizeof(char *) * (buffs + 2));
	if (tok == NULL)
		return (NULL);

	while (usr_inp[s] != '\0')
		s++;
	while (j < s)
	{
		len = t_strlen(usr_inp, j, tem);
		tok[a] = malloc(sizeof(char) * (len + 1));
		if (tok[a] == NULL)
			return (NULL);
		i = 0;
		while ((usr_inp[j] != tem) &&
				(usr_inp[j] != '\0'))
		{
			tok[a][i] = usr_inp[j];
			i++;
			j++;
		}
		tok[a][i] = '\0';
		a++;
		j++;
	}
	tok[a] = NULL;
	return (tok);
}

