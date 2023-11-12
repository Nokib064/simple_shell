#include "shell.h"

/**
 * ctrl_c - ignore ctrl-c command
 * @n: unsused input
 * Return: nothing
 */

void ctrl_c(int  __attribute__((unused))n)
{
	char *newline_prompt = "\nCAPREET$: ";

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, newline_prompt, _strlen(newline_prompt));
	}
}

#include "shell.h"
/**
 * ctrl_d - to exit one pressed
 * @a: input to be read from getline func
 * @command: user input
 * @env: linked list of enviro var
 */

void ctrl_d(int a, char *command, list_s *env)
{
	char newline = '\n';

	if (a == 0)
	{
		free(command);
		free(env);
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, &newline, 1);
		}
		exit(0);
	}
}

#include "shell.h"
/**
 * prompt - prompts user for input and then execute
 * @env_var: environ variable
 * Return: nothing
 */
int prompt(char **env_var)
{
	list_s *env_list;
	size_t j = 0, b = 0;
	int cmd_line_num = 0, exit_stat = 0, prompt_active = 1;
	char *command, *n_command, **tokenize;

	env_list = environ_list((char *)env_var);
	while (prompt_active)
	{
		cmd_line_num++;
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "CAPREET$: ", 11);
		}
		else
		{
			NonInteractive(env_list);
		}
		signal(SIGINT, ctrl_c);
		command = NULL;
		j = get_line(&command);
		ctrl_d(j, command, env_list);
		n_command = command;
		command = ignore_space(command);
		while (command[b] != '\n')
		{
			b++;
		}
		command[b] = '\0';
		if ((command[0] == '\0'))
		{
			free(n_command);
			continue;
		}
		tokenize = NULL;
		tokenize = _strtok(command, " ");
		free(n_command);
		exit_stat = built_in(tokenize, env_list, cmd_line_num, NULL);
		if (exit_stat)
		{
			continue;
		}
		exit_stat = _execve(tokenize, env_list, cmd_line_num);
	}
	return (exit_stat);
}

#include "shell.h"
/**
 * get_line - reads and stores input ffrom user
 * @input_str: user input
 * Return: user inputs
 */
size_t get_line(char **input_str)
{
	ssize_t a = 0, size = 0, bool_val = 0;
	size_t m;
	char buffer_arr[1024];

	a = read(STDIN_FILENO, buffer_arr, 1024 - 1);
	if (a == -1)
	{
		return (-1);
	}
	buffer_arr[a] = '\0';
	for (m = 0; buffer_arr[m] != '\0'; m++)
	{
		if (buffer_arr[m] == '\n')
		{
			bool_val = 1;
			break;
		}
	}
	if (a > 0)
	{
		*input_str = malloc(sizeof(char) * (a + 1));
		if (*input_str == NULL)
		{
			return (-1);
		}
		*input_str = _strcpy(*input_str, buffer_arr);
		size = a + 1;
	}
	if (!bool_val)
	{
		size += get_line(input_str);
	}
	return (size);
}
