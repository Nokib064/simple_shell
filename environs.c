#include "shell.h"

/**
 * get_line - gets user input command and stores it
 * @str_buf: buffer
 * Return: number of characters read
 */
size_t _getline(char **str_buf)
{
	ssize_t i = 0, size = 0, a = 0, b = 0, n;
	char buff[1024];

	while (b == 0 && (i = read(STDIN_FILENO, buff, 1024 - 1)))
	{
		if (i == -1)
			return (-1);

		buff[i] = '\0';

		for (n = 0; buff[n] != '\0'; n++)
		{
			if (buff[n] == '\n')
				b = 1;
		}

		if (a == 0)
		{
			i++;
			*str_buf = malloc(sizeof(char) * i);
			*str_buf = _strcpy(*str_buf, buff);
			size = i;
			a = 1;
		}
		else
		{
			size += i;
			*str_buf = _strcat(*str_buf, buff);
		}
	}
	return (size);
}

#include "shell.h"
/**
 * ctrl_c - ignore Ctrl-C input and prints prompt again
 * @num: takes in int from signal
 */
void ctrl_c(int num)
{
	(void)num;
	write(STDOUT_FILENO, "\nCAPREET$ ", 10);
}

#include "shell.h"
/**
 * built_in - handles builtins oommand
 * @usr_cmd:  command inputted from user
 * @env_var: environmental variable
 * @num: user input  to write error message
 * @command: bring in command to free
 * Return: 1 if acted on builtin, else 0
 */
int built_in(char **usr_cmd, list_s *env_var, int num, char **command)
{
	int a = 0;

	if (_strcmp(usr_cmd[0], "exit") == 0)
	{
		a = __exit(usr_cmd, env_var, num, command);
	}
	else if (_strcmp(usr_cmd[0], "env") == 0)
	{
		_env(usr_cmd, env_var);
		a = 1;
	}
	else if (_strcmp(usr_cmd[0], "cd") == 0)
	{
		a = _cd(usr_cmd, env_var, num);
	}

	else if (_strcmp(usr_cmd[0], "setenv") == 0)
	{
		_setenv(&env_var, usr_cmd);
		a = 1;
	}
	else if (_strcmp(usr_cmd[0], "unsetenv") == 0)
	{
		_unsetenv(&env_var, usr_cmd);
		a = 1;
	}
	return (a);
}


#include "shell.h"
/**
 * ignore_space - return string without spaces in front
 * @str: string
 * Return: new string
 */
char *ignore_space(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

#include "shell.h"

/**
 * prompt - repeatedly prompts user and executes user's cmds if applicable
 * @environ_var: envrionmental variables
 * Return: 0 on success
 */
int prompt(char **environ_var)
{
	list_s *envir;
	size_t a = 0, b = 0;
	int command_lineNum = 0, exit_stat = 0;
	char *comnd, *n_comnd, **tok;

	envir = env_linkedList(environ_var);
	do {
		command_lineNum++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "CAPREET$ ", 9);
		else
			NonInteractive(envir);
		signal(SIGINT, ctrl_c);
		comnd = NULL;
		a = 0;
		a = _getline(&comnd);
		ctrl_D(a, comnd, envir);
		n_comnd = comnd;
		comnd = ignore_space(comnd);
		b = 0;
		while (comnd[b] != '\n')
			b++;
		comnd[b] = '\0';
		if (comnd[0] == '\0')
		{
			free(n_comnd);
			continue;
		}
		tok = NULL;
		tok = _str_tok(comnd, " ");
		if (n_comnd != NULL)
			free(n_comnd);
		exit_stat = built_in(tok, envir, command_lineNum, NULL);
		if (exit_stat)
			continue;
		exit_stat = _execve(tok, envir, command_lineNum);
	} while (1);
	return (exit_stat);
}


