#include "shell.h"

/**
 * custom_exit - free user input command and linked-list before exit
 * @user_cmd: input command from user
 * @env_list: environment linked-list
 */
void custom_exit(char **user_cmd, list_s *env_list)
{
	db_ptr_free(user_cmd);
	free_linkedList(env_list);
	_exit(0);
}

#include "shell.h"
/**
 * _execve - executes user typed-in command in shell
 * @usr_inp: typed-in command
 * @env_var: environmental variable
 * @numb: nth user command; for error message
 * Return: 0
 */
int _execve(char **usr_inp, list_s *env_var, int numb)
{
	char *holdr;
	int status = 0, a = 0;
	pid_t pid;

	if (access(usr_inp[0], F_OK) == 0)
	{
		holdr = usr_inp[0];
		a = 1;
	}

	else
		holdr = _which(usr_inp[0], env_var);

	if (access(holdr, X_OK) != 0)
	{
		not_available(usr_inp[0], numb, env_var);
		db_ptr_free(usr_inp);
		return (127);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(holdr, usr_inp, NULL) == -1)
			{
				not_available(usr_inp[0], numb, env_var);
				custom_exit(usr_inp, env_var);
			}
		}
		else
		{
			wait(&status);
			db_ptr_free(usr_inp);
			if (a == 0)
				free(holdr);
		}
	}
	return (0);
}

#include "shell.h"
/**
 * custom_atoi - converts string to integer
 * @str: string
 * Return: number if success, else -1
 */
int custom_atoi(char *str)
{
	int a = 0;
	unsigned int num = 0;

	while (str[a] != '\0')
	{
		if (str[a] >= '0' && str[a] <= '9')
			num = num * 10 + (str[a] - '0');
		if (str[a] > '9' || str[a] < '0')
			return (-1);
		a++;
	}
	return (num);
}

#include "shell.h"
/**
 * _exit - frees user input and then exits main program with a value
 * @usr_str: user command input
 * @env_var: environmental variable to be freed
 * @num: nth user command line input to print in error message
 * @comd: command to be freed
 * Return: 0 if success 2 if fail
 */
int __exit(char **usr_str, list_s *env_var, int num, char **comd)
{
	int val = 0;

	if (usr_str[1] != NULL)
		val = custom_atoi(usr_str[1]);

	if (val == -1)
	{
		invalid_number(usr_str[1], num, env_var);
		db_ptr_free(usr_str);
		return (2);
	}
	db_ptr_free(usr_str);
	free_linkedList(env_var);
	if (comd != NULL)
		db_ptr_free(comd);
	exit(val);
}
#include "shell.h"
/**
 * ctrl_D - exits program if Ctrl-D was pressed
 * @char_rd: characters read via get_line
 * @usr_cmd: user command input
 * @env_llst: environmental variable linked list
 */
void ctrl_D(int char_rd, char *usr_cmd, list_s *env_llst)
{
	if (char_rd == 0)
	{
		free(usr_cmd);
		free_linkedList(env_llst);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
}

