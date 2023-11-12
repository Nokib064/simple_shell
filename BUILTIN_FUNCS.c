#include "shell.h"

/**
 * _prog_exit - exits main program and frees user input
 * @str: user command
 * @env: environ var linked list
 * @num: command line (nth)input to printt in err msg
 * @command: command to be freed
 * Return: if success 0, otherwise 2
 */

int _prog_exit(char **str, list_s *env, int num, char **command)
{
	int exit_value = 0;

	if (str[1] != NULL)
		exit_value =  _atoi(str[1]);
	if (exit_value == -1)
	{
		illegal_num(str[1], num, env);
		db_ptr_free(str);
		return (2);
	}
	free(str);
	free(env);

	if (command != NULL)
		free(command);
	exit(exit_value);
}

#include "shell.h"

/**
 * custom_exit - frees user input and linkedList before exit
 * @str: user input
 * @env: eviron var linked list
 * Return: nothing
 */


void custom_exit(char **str, list_s *env)
{
	db_ptr_free(str);
	freeLinkedList(env);
	exit(0);
}

#include "shell.h"
/**
 * built_in - handles built in command
 * @tok: user input tok
 * @env_list: linkedList eviron var
 * @num: number of user input
 * @cmd: defined structure
 * Return: built in acted upon =1, else 0
 */


int built_in(char **tok, list_s *env_list, int num, char **cmd)
{
	int a = 0;

	if (!_strcmp(tok[0], "exit"))
	{
		a = _prog_exit(tok, env_list, num, cmd);
	}
	else if (!_strcmp(tok[0], "env"))
	{
		envar_print(tok, env_list);
		a = 1;
	}
	else if (!_strcmp(tok[0], "cd"))
	{
		a = _cd(tok, env_list, num);
	}
	else if (!_strcmp(tok[0], "setenv"))
	{
		set_env(&env_list, tok);
		a = 1;
	}
	else if (!_strcmp(tok[0], "unsetenv"))
	{
		un_set_env(&env_list, tok);
		a = 1;
	}

	return (a);

}

#include "shell.h"
/**
 * _execve - executtes user input
 * @s: user input
 * @env: enviomental var
 * @num: user input(nth)
 * Return: 0 on success
 */
int _execve(char **s, list_s *env, int num)
{
	char *command_path;
	int status = 0;
	pid_t pid;

	if (access(s[0], F_OK) == 0)
	{
		command_path = s[0];
	}
	else
	{
		command_path = _which(s[0], env);
	}
	if (access(command_path, X_OK) != 0)
	{
		not_available(s[0], num, env);
		/*free(s);*/
		return (127);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(command_path, s, NULL) == -1)
			{
				not_available(s[0], num, env);
				free(env);
			}
		}
		else
		{
			wait(&status);
			free(s);
			if (access(s[0], F_OK) != 0)
			{
				free(command_path);
			}
		}
	}
	return (0);
}

