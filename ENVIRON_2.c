#include "shell.h"


/**
 * env_list_finder - look for environmental variable in linked list.
 * @env_lst: Environ var linked list.
 * @str: Variable name.
 * Return: Index of node in linked list if found, -1 otherwise.
 */
int env_list_finder(list_s *env_lst, char *str)
{
	int index = 0;

	while (env_lst != NULL)
	{
		if (_strcmp(env_lst->var, str) == 0)
			return (index);

		env_lst = env_lst->next;
		index++;
	}

	return (-1);
}
#include "shell.h"
/**
 * envar_print - prints environmental variables
 * @str: user's command
 * @env_var: environmental var
 * Return: 0 on success
 */

int envar_print(char **str, list_s *env_var)
{
	free(str);
	LinkedList(env_var);
	return (0);
}
#include "shell.h"
/**
 * get_env -look for copy of the requested environmental variableand returns it
 * @var_name: environmental var name to retrieve
 * @env_total: environmental variables LinkedList
 * Return: copy of requested environmental variable or NULL
 */
char *get_env(char *var_name, list_s *env_total)
{
	if (var_name == NULL || env_total == NULL)
		return (NULL);

	while (env_total != NULL)
	{
		char *current_var_name;

		current_var_name = (char *)_strtok(env_total->var, "=");

		if (_strcmp(current_var_name, var_name) == 0)
		{
			return (custom_strdup(env_total->var, strlen(var_name) + 1));
		}
		env_total = env_total->next;
	}

	return (NULL);
}

#include "shell.h"
/**
 * set_env - add or update environmental variable in linked list.
 * @env: environmental variables LinkedList
 * @str: User's input command
 * Return: 0 on success, -1 on failure.
 */
int set_env(list_s **env, char **str)
{
	int indexx, j;
	char *new_var;


	if (str[1] == NULL || str[2] == NULL)
	{
		write(STDOUT_FILENO, "Incomplete arguments\n", 21);
		/*db_ptr_free(str);*/
		return (-1);
	}


	new_var = _strcat(str[1], "=");
	new_var = _strcat(new_var, str[2]);


	indexx = env_list_finder(*env, str[1]);


	if (indexx == -1)
	{
		Add_NodeToEnd(env, new_var);
	}
	else
	{
		list_s *holder = *env;

		while (indexx > j)
		{
			holder = holder->next;
			j++;
		}
		free(holder->var);
		holder->var = _strdup(new_var);
	}


	free(new_var);
	free(str);
	return (0);
}

#include "shell.h"
/**
 * un_set_env - unset node from environmental linked list.
 * @env: environmental variable linked list
 * @str: User's input command
 * Return: 0 on success, -1 on failure.
 */
int un_set_env(list_s **env, char **str)
{
	int indexx;


	if (str[1] == NULL)
	{
		write(STDOUT_FILENO, "Incomplete arguments\n", 21);
		/*db_ptr_free(str);*/
		return (-1);
	}


	indexx = env_list_finder(*env, str[1]);
	free(str);


	if (indexx == -1)
	{
		write(STDOUT_FILENO, "not foundd\n", 12);
		return (-1);
	}


	if (Delete_NodeAtIndex(env, indexx) == -1)
	{
		write(STDOUT_FILENO, "not found\n", 12);
		return (-1);
	}


	return (0);
}


