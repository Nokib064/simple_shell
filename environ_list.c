#include "shell.h"

/**
 * cusom_t_size - returns number of delimiters
 * @str: user input command
 * @delim: delimeter
 * Return: number of tokens
 */
int custom_t_size(char *str, char delim)
{
	int i = 0, num_delm = 0;

	while (str[i] != '\0')
	{
		if (str[i] == delim)
		{
			num_delm++;
		}
		i++;
	}
	return (num_delm);
}
#include "shell.h"

/**
 * custom_strdup - custom string duplication; excludes beginning bytes
 * @str: string to duplicate (e.g. environmental variable PATH=/bin:/bin/ls)
 * @exc: number of bytes to exclude (e.g. excludes "PATH=")
 * Return: string (e.g. /bin:/bin/ls)
 */
char *custom_strdup(char *str, int exc)
{
	char *dupl;
	int i, len = 0;

	if (str == NULL)
		return (NULL);


	while (*(str + len))
		len++;
	len++;

	dupl = malloc(sizeof(char) * (len - exc));
	if (dupl == NULL)
		return (NULL);

	i = 0;
	while (i < (len - exc))
	{
		*(dupl + i) = *(str + exc + i);
		i++;
	}
	return (dupl);
}
#include "shell.h"
/**
 * _getenv - finds and returns a copy of the requested environmental variable
 * @str: string to store it in
 * @env_var: entire set of environmental variables
 * Return: copy of requested environmental variable
 */
char *_getenv(char *str, list_s *env_var)
{
	int i = 0, exc = 0;

	while (env_var != NULL)
	{
		i = 0;
		while ((env_var->var)[i] == str[i])
			i++;
		if (str[i] == '\0' && (env_var->var)[i] == '=')
			break;
		env_var = env_var->next;
	}

	while (str[exc] != '\0')
		exc++;
	exc++;
	return (custom_strdup(env_var->var, exc));
}

#include "shell.h"

/**
 * env_linkedList - creates environmental variables' linkedList
 * @env_var: environmental variables
 * Return: linked list
 */
list_s *env_linkedList(char **env_var)
{
	list_s *h;
	int i = 0;

	h = NULL;
	while (env_var[i] != NULL)
	{
		addNode_atEnd(&h, env_var[i]);
		i++;
	}
	return (h);
}
#include "shell.h"
/**
 * _env - prints environmental variables
 * @usr_inp: user's input command
 * @env_var: environmental variables
 * Return: 0 on success
 */
int _env(char **usr_inp, list_s *env_var)
{
	db_ptr_free(usr_inp);
	printList(env_var);
	return (0);
}


