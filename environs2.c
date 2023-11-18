#include "shell.h"

/**
 * custom_strcat - concatenate two strings ignoring the first character
 * @dest: string to be appended to
 * @src: string to append
 * Return: concatenated string
 */
char *custom_strcat(char *dest, char *src)
{
	int len = 0;
	int len2 = 0;
	int total_len = 0;
	int j = 0;

	while (dest[len] != '\0')
	{
		len++;
		total_len++;
	}
	while (src[len2] != '\0')
	{
		len2++;
		total_len++;
	}

	dest = _realloc(dest, len, sizeof(char) * total_len + 1);

	j = 1;
	while (src[j] != '\0')
	{
		dest[len] = src[j];
		len++;
		j++;
	}
	dest[len] = '\0';

	return (dest);
}


#include "shell.h"

/**
 * custom_setenv - customized settenvv
 * @env_llst: environmental variable linked list
 * @env_name: environmental variable name
 * @dir_pth: directory path
 * Return: 0 on success (e.g. "OLDPWD=/home/vagrant/directory1")
 */
int custom_setenv(list_s **env_llst, char *var_name, char *dir_pth)
{
	int index = 0, j = 0;
	char *tem;
	list_s *holder;

	tem = _strdup(var_name);
	tem = _strcat(tem, "=");
	tem = _strcat(tem, dir_pth);
	index = env_finder(*env_llst, var_name);

	holder = *env_llst;
	while (j < index)
	{
		holder = holder->next;
		j++;
	}
	free(holder->var);
	holder->var = _strdup(tem);
	free(tem);
	return (0);
}
#include "shell.h"
/**
 * just_cd - change directory to home
 * @env_llst: environmental linked list to update PATH and OLDPWD
 * @curr_dir: current working directotry
 */
void just_cd(list_s *env_llst, char *curr_dir)
{
	char *home = NULL;

	home = _getenv("HOME", env_llst);
	custom_setenv(&env_llst, "OLDPWD", curr_dir);
	free(curr_dir);
	if (access(home, F_OK) == 0)
		chdir(home);
	curr_dir = NULL;
	curr_dir = getcwd(curr_dir, 0);
	custom_setenv(&env_llst, "PWD", curr_dir);
	free(curr_dir);
	free(home);
}

#include "shell.h"
/**
 * cd_executor - executes the cd
 * @env_llst: environmental linked list to update PATH and OLDPWD
 * @curr_dir: bring in current working directotry
 * @dir: bring in directory path to change to
 * @arg: 1st argument to write out error
 * @num: bring in the line number to write out error
 * Return: 0 if success 2 if fail
 */
int cd_executor(list_s *env_llst, char *curr_dir,
		char *dir, char *arg, int num)
{
	int i = 0;

	if (access(dir, F_OK) == 0)
	{
		custom_setenv(&env_llst, "OLDPWD", curr_dir);
		free(curr_dir);
		chdir(dir);
		curr_dir = NULL;
		curr_dir = getcwd(curr_dir, 0);
		custom_setenv(&env_llst, "PWD", curr_dir);
		free(curr_dir);
	}
	else
	{
		unable_toCd(arg, num, env_llst);
		free(curr_dir);
		i = 2;
	}
	return (i);
}

#include "shell.h"
/**
 * _cd - change directory
 * @usr_inp: user's input command
 * @env_llst: enviromental linked list to retrieve HOME and OLDPWD paths
 * @num: nth user command, to be used at error message
 * Return: 0 if success 2 if failed
 */
int _cd(char **usr_inp, list_s *env_llst, int num)
{
	char *curr_dir = NULL, *dir = NULL;
	int exit_stat = 0;

	curr_dir = getcwd(curr_dir, 0);
	if (usr_inp[1] != NULL)
	{
		if (usr_inp[1][0] == '~')
		{
			dir = _getenv("HOME", env_llst);
			dir = custom_strcat(dir, usr_inp[1]);
		}
		else if (usr_inp[1][0] == '-')
		{
			if (usr_inp[1][1] == '\0')
				dir = _getenv("OLDPWD", env_llst);
		}
		else
		{
			if (usr_inp[1][0] != '/')
			{
				dir = getcwd(dir, 0);
				dir = _strcat(dir, "/");
				dir = _strcat(dir, usr_inp[1]);
			}
			else
				dir = _strdup(usr_inp[1]);
		}
		exit_stat = cd_executor(env_llst, curr_dir, dir, usr_inp[1], num);
		free(dir);
	}
	else
		just_cd(env_llst, curr_dir);
	db_ptr_free(usr_inp);
	return (exit_stat);
}


