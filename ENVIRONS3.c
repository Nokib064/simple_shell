#include "shell.h"

/**
 * env_finder - find given environmental variable in linked list
 * @env_llst: environmental variable linked list
 * @var_name: variable name
 * Return: index of node in linked list
 */
int env_finder(list_s *env_llst, char *var_name)
{
	int i = 0, index = 0;

	while (env_llst != NULL)
	{
		i = 0;
		while ((env_llst->var)[i] == var_name[i])
			i++;
		if (var_name[i] == '\0')
			break;
		env_llst = env_llst->next;
		index++;
	}
	if (env_llst == NULL)
		return (-1);
	return (index);
}
#include "shell.h"
/**
 * _unsetenv - unset node in environmental linked list
 * @env_llst: linked list
 * @usr_inp: user input command
 * Return: 0 on success
 */
int _unsetenv(list_s **env_llst, char **usr_inp)
{
	int index = 0, i = 0;

	if (usr_inp[1] == NULL)
	{
		write(STDOUT_FILENO, "arguments incomplete\n", 21);
		db_ptr_free(usr_inp);
		return (-1);
	}
	index = env_finder(*env_llst, usr_inp[1]);
	db_ptr_free(usr_inp);
	if (index == -1)
	{
		write(STDOUT_FILENO, "Not found\n", 10);
		return (-1);
	}
	i = deleteNode_atIndex(env_llst, index);
	if (i == -1)
	{
		write(STDOUT_FILENO, "Not found\n", 10);
		return (-1);
	}
	return (0);
}
#include "shell.h"
/**
 * _setenv - sets environmental variable in linked list
 * @env_llst: linked list
 * @usr_inp: user input command
 * Return: 0 on success, 1 on fail
 */
int _setenv(list_s **env_llst, char **usr_inp)
{
	int index = 0, i = 0;
	char *tem;
	list_s *holder;

	if (usr_inp[1] == NULL || usr_inp[2] == NULL)
	{
		write(STDOUT_FILENO, "incomplete arguments\n", 21);
		db_ptr_free(usr_inp);
		return (-1);
	}
	tem = _strdup(usr_inp[1]);
	tem = _strcat(tem, "=");
	tem = _strcat(tem, usr_inp[2]);
	index = env_finder(*env_llst, usr_inp[1]);
	if (index == -1)
	{
		addNode_atEnd(env_llst, tem);
	}
	else
	{
		holder = *env_llst;
		while (i < index)
		{
			holder = holder->next;
			i++;
		}
		free(holder->var);
		holder->var = _strdup(tem);
	}
	free(tem);
	db_ptr_free(usr_inp);
	return (0);
}

#include "shell.h"

/**
 * numlen - counts number of 0s in a tens power number
 * @num: number
 * Return: returns count of digits
 */
int numlen(int num)
{
	int num_count = 0;
	int a = num;

	while (a > 9 || a < -9)
	{
		a /= 10;
		num_count++;
	}
	return (num_count);
}
