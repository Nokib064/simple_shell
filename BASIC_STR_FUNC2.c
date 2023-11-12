#include "shell.h"

/**
 * custom_strcat - Concatenates two strings
 * @dest:The destination string to which src will be appended.
 * @src:The source string that will be concatenated to dest.
 * Return:A dynamically allocated string containing the concatenated result.
 */

char *custom_strcat(char *dest, char *src)
{
	int src_index = 1; /* Begin at index 1 to ignore the first character*/
	int dest_len = _strlen(dest);
	int total_len = dest_len + _strlen(src) - 1; /* ignore the first character */

	dest = custom_malloc(dest, dest_len, sizeof(char) * (total_len + 1));
	for (; src[src_index] != '\0'; src_index++)
	{
		dest[dest_len] = src[src_index];
		dest_len++;
	}

	dest[dest_len] = '\0';

	return (dest);
}

#include "shell.h"
/**
 * custom_strdup - duplicates a string excluding the initial bytes
 * @str: string to duplicate (e.g. environmental variable PATH=/bin:/bin/ls)
 * @bytes_excl: number of bytes to exclude (e.g. excludes "PATH=")
 * Return: duplicated string (e.g. /bin:/bin/ls)
 */
char *custom_strdup(char *str, int bytes_excl)
{
	char *dup_str;
	int i;

	if (str == NULL || bytes_excl < 0)
		return (NULL);

	i = _strlen(str);

	if (bytes_excl >= i)
		return (NULL);

	dup_str = malloc((i - bytes_excl + 1) * sizeof(char));

	if (dup_str == NULL)
		return (NULL);

	_strcpy(dup_str, str + bytes_excl);
	return (dup_str);
}
#include "shell.h"
/**
 * custom_t_size - returns the number of delimiters in a string
 * @str: user's command typed into the shell
 * @delim: delimiter (e.g., ' ')
 * Return: number of tokens
 */
int custom_t_size(char *str, char delim)
{
	int i = 0;
	int num_delimiters = 0;

	while (str[i] != '\0')
	{
		if (str[i] == delim)
		{
			num_delimiters++;
		}
		i++;
	}

	return (num_delimiters);
}

#include "shell.h"
/**
 * custom_strtok - tokenizes a string even with delimiters, and empty strings
 * (e.g., path: ":/bin::/bin/usr")
 * @str: user's command typed into the shell
 * @delim: delimiter (e.g., " ")
 * Return: an array of tokens (e.g., {"\0", "/bin", "\0", "/bin/usr"})
 * (purpose: allow commands to search directory if there is a delimiter ":")
 */
char **custom_strtok(char *str, char *delim)
{
	int buffsize = 0, pos = 0, si = 0, i = 0, len = 0, se = 0;
	char **tokens = NULL, delim_char;

	/* set delimiter character (" ") */
	delim_char = delim[0];

	/* calculate the number of tokens */
	buffsize = custom_t_size(str, delim_char);
	/* allocate memory for the array of tokens and NULL pointer */
	tokens = malloc(sizeof(char *) * (buffsize + 2));
	if (tokens == NULL)
		return (NULL);
	/* find the end index of the string */
	while (str[se] != '\0')
		se++;

	while (si < se)
	{
		/* determine the length for each token in the array */
		len = t_strlen(str, si, delim_char);
		/* allocate memory for the token */
		tokens[pos] = malloc(sizeof(char) * (len + 1));
		if (tokens[pos] == NULL)
			return (NULL);

		i = 0;
		while ((str[si] != delim_char) &&
				(str[si] != '\0'))
		{
			tokens[pos][i] = str[si];
			i++;
			si++;
		}

		tokens[pos][i] = '\0'; /* null terminate the token */
		pos++;
		si++;
	}
	tokens[pos] = NULL; /* set the last array element to NULL */
	return (tokens);
}
