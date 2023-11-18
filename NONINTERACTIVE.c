/**
 * custom_ignore - custom ignores spaces and newlines
 * @env_var: envrionmental variables
 * Return: new string
 */
char *custom_ignore(char *env_var)
{
	while (*env_var == ' ' || *env_var == '\n')
		env_var++;
	return (env_var);
}
#include "shell.h"
/**
 * NonInteractive - handles when user pipes commands into shell via pipe
 * @env_var: envrionmental variables
 */
void NonInteractive(list_s *env_var)
{
	size_t i = 0, n = 0;
	int command_line_num = 0, exit_stat = 0;
	char *comnd = NULL, *n_comnd = NULL, **n_line, **tok;

	i = _getline(&comnd);
	if (i == 0)
	{
		free(comnd);
		exit(0);
	}
	n_comnd = comnd;
	comnd = custom_ignore(comnd);
	n_line = _str_tok(comnd, "\n");
	if (n_comnd != NULL)
		free(n_comnd);
	n = 0;
	while (n_line[n] != NULL)
	{
		command_line_num++;
		tok = NULL;
		tok = _str_tok(n_line[n], " ");
		exit_stat = built_in(tok, env_var, command_line_num, n_line);
		if (exit_stat)
		{
			n++;
			continue;
		}
		exit_stat = _execve(tok, env_var, command_line_num);
		n++;
	}
	db_ptr_free(n_line);
	free_linkedList(env_var);
	exit(exit_stat);
}
