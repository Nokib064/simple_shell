#include "shell.h"
/**
 * simple_cd - function changes dir to home
 * @update_env: brings environ LList to update path
 * @workdir_current: current working directory
 * Return: nothing
 */
void simple_cd(list_s *update_env, char *workdir_current)
{
	char *rt_dir = get_env("HOME", update_env);

	custom_setenv(&update_env, "PREV_PWD", workdir_current);
	/*free(workdir_current);*/

	if (rt_dir != NULL && access(rt_dir, F_OK) == 0)
	{
		chdir(rt_dir);
		workdir_current = getcwd(NULL, 0);
	}
	else
	{
		workdir_current = _strdup("");
	}

	custom_setenv(&update_env, "PWD", workdir_current);
	free(rt_dir);
	free(workdir_current);
}
#include "shell.h"
/**
 * currentdir_executor - executes the cd command
 * @update_env: brings environ LList to update
 * @workdir_current: current working directory
 * @path_update: directory path to change to
 * @first_arg: first argument (error)
 * @line_num: line number to write error
 * Return: 0 on success, 2 otherwise
 */

int currentdir_executor(list_s *update_env, char *workdir_current,
		char *path_update, char *first_arg, int line_num)
{
	int result = 0;

	if (access(path_update, F_OK) == 0)
	{
		custom_setenv(&update_env, "PREV_PWD", workdir_current);
		/*free(workdir_current);*/
		if (chdir(path_update) == 0)
		{
			workdir_current = getcwd(NULL, 0);
			custom_setenv(&update_env, "PWD", workdir_current);
			/*free(workdir_current);*/
		}
		else
		{
			result = 2;
		}
	}
	else
	{
		cd_to_impossible(first_arg, line_num, update_env);
		free(workdir_current);
		result = 2;
	}

	return (result);
}


#include "shell.h"
/**
 * custom_setenv - customized setenv by concatenating first prior to setenv
 * @envar_list: linkedlist for env variables
 * @envar_name: env var name
 * @dir_pth: directory path
 * Return: 0
 */
int custom_setenv(list_s **envar_list, char  *envar_name, char *dir_pth)
{
	int index = 0, j;
	char *cat;
	list_s *holder;

	cat = malloc(_strlen(envar_name) + 1 + _strlen(dir_pth) + 1);

	_strcpy(cat, envar_name);
	_strcat(cat, "=");
	_strcat(cat, dir_pth);

	index = env_list_finder(*envar_list, envar_name);


	holder = *envar_list;
	for (j = 0; j < index; j++)
	{
		holder = holder->next;
	}
	return (0);
}
#include "shell.h"
/**
 * _cd - changes directory
 * @user_cmd: user input command
 * @update_env: llist for env var
 * @num: nth input to be used as error output
 * Return: 0 if successful, else 2
 */
int _cd(char **user_cmd, list_s *update_env, int num)
{
	char *present_dir = NULL, *dir = NULL;
	int exit_stat = 0;

	present_dir = getcwd(NULL, 0);
	if (user_cmd[1] != NULL)
	{
		if (user_cmd[1][0] == '~')
		{
			dir = get_env("HOME", update_env);
			dir = custom_strcat(dir, user_cmd[1]);
		}
		else if (user_cmd[1][0] == '-')
		{
			if (user_cmd[1][1] == '\0')
			{
				dir = get_env("PREVPWD", update_env);
			}
		}
		else
		{
			if (!(user_cmd[1][0] == '/'))
			{
				dir = getcwd(dir, 0);
				dir = _strcat(dir, "/");
				dir = _strcat(dir, user_cmd[1]);
			}
			else
			{
				dir = _strdup(user_cmd[1]);
			}
		}
		exit_stat = currentdir_executor(update_env,
				present_dir, dir, user_cmd[1], num);
		free(dir);
	}
	else
	{
		simple_cd(update_env, present_dir);
	}
	return (exit_stat);
}

#include "shell.h"
/**
 * _which - fleshes out command by appending it to a matching PATH directory
 * @first_cmd: first typed in command by user
 * @env: environmental variable
 * Return: a copy of fleshed out command
 */

char *_which(char *first_cmd, list_s *env)
{
	char *path = get_env("PATH", env);
	char *path_copy = _strdup(path);
	char *token;

	free(path);

	token = (char *) _strtok(path_copy, ":");

	while (token != NULL)
	{
		char *command_path;

		command_path = _strcat(_strcat(_strdup(token), "/"), first_cmd);

		if (access(command_path, F_OK) == 0)
		{
			free(path_copy);
			return (command_path);
		}
		free(command_path);
		token = (char *) _strtok(NULL, ":");
	}

	/*free(path_copy);*/
	return (first_cmd);
}


