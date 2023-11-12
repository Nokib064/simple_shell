#include "shell.h"
#include <stdio.h>
/**
 * _strcpy - copy string pointed to by src to buffer pointed to by dest
 * @src: string to be copied
 * @dest: destination to copy to
 * Return: 0
 */

char *_strcpy(char *dest, char *src)

{
	int temp = 0;

	while (src[temp] != '\0')

	{
		dest[temp] = src[temp];
		temp++;

	}

	dest[temp] = '\0';
	return (dest);
}
#include "shell.h"
/**
 * _strcmp - compares two strings
 * @s1: first string to be compared
 * @s2: second string to be compared
 * Return: 0
 */

int _strcmp(char *s1, char *s2)

{
	int i = 0;
	int j = 0;
	int temp;

	while (s1[i] != '\0')

		i++;

	while (s2[j] != '\0')

	{
		j++;
		temp = *s1 - *s2;
		return (temp);
	}
	return (0);
}

#include "shell.h"
/**
 * _strcat- function that cocatenates two strings
 * @dest: first string
 * @src: second string
 * Return: pointer to resulting string
 */
char *_strcat(char *dest, char *src)

{

	int i = 0;
	int j = 0;

	while (dest[i] != '\0')

	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	/*	dest[i] != '\0';*/
	return (dest);
}

#include "shell.h"
/**
 * _strdup - function returns pointer to duplicate of a string
 * @str: duplicate of the string
 *
 * Return: null
 */
char *_strdup(char *str)
{
	char *a;
	unsigned int b, c;

	b = 0;
	c = 0;

	if (str == NULL)
		return (NULL);

	while (str[c])
		c++;
	a = malloc(sizeof(char) * (c + 1));

	if (a == NULL)
		return (NULL);

	while (!(a[b] = str[b]) == '\0')
		b++;

	return (a);
}

#include "shell.h"
/**
 * _strtok - tokenizes a string and returns an array of tokens
 * @str: user's command typed into shell
 * @delm: delimeter (e.g. " ");
 * Return: an array of tokens (e.g. {"ls", "-l", "/tmp"}
 */
char **_strtok(char *str, char *delm)
{
	int buffsize = 0, p = 0, si = 0, i = 0, len = 0, se = 0, t = 0;
	char **toks = NULL, d_ch;

	d_ch = delm[0];
	/* creates new version of string ignoring all delims infront*/
	str = ignore_delimet(str, d_ch);
	/* malloc ptrs to store array of tokens (buffsize + 1), and NULL ptr */
	buffsize = t_size(str, d_ch);
	toks = malloc(sizeof(char *) * (buffsize + 2));
	if (toks == NULL)
		return (NULL);
	while (str[se] != '\0')	/* find string ending index */
		se++;
	while (si < se)
	{ /* malloc lengths for each token ptr in array */
		if (str[si] != d_ch)
		{
			len = t_strlen(str, si, d_ch);
			toks[p] = malloc(sizeof(char) * (len + 1));
			if (toks[p] == NULL)
				return (NULL);
			i = 0;
			while ((str[si] != d_ch) && (str[si] != '\0'))
			{
				toks[p][i] = str[si];
				i++;
				si++;
			}
			toks[p][i] = '\0'; /* null terminate at end*/
			t++;
		}
		/* handle repeated delimeters; increment ptr after ("ls __-l")*/
		if (si < se && (str[si + 1] != d_ch && str[si + 1] != '\0'))
			p++;
		si++;
	}
	p++;
	toks[p] = NULL; /* set last array ptr to NULL */
	return (toks);
}
