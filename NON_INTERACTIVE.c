#include "shell.h"

/**
 * NonInteractive - processes commands when user pipes commands into the shell
 * (e.g., echo "ls\nls -al\n" | ./a.out)
 * @env: environmental variables
 */
void NonInteractive(list_s *env)
{
	size_t i = 0, n = 0;
	int command_line_no = 0, exit_stat = 0;
	char *command = NULL, *original_command = NULL, **command_lines, **tokens;

	i = get_line(&command);
	if (i == 0)
	{
		free(command);
		exit(0);
	}
	original_command = command;
	command = skipSpacesAndNewlines(command);
	command_lines = _strtok(command, "\n"); /* tokenize each command string */
	if (original_command != NULL)
	{
		free(original_command);
		n = 0;
	}
	/*n = 0;*/
	while (command_lines[n] != NULL)
	{
		command_line_no++;
		tokens = NULL; /* tokenize each command in the array of commands */
		tokens = _strtok(command_lines[n], " ");
		exit_stat = built_in(tokens, env, command_line_no, command_lines);
		if (exit_stat)
		{
			n++;
			continue;
		}
		exit_stat = _execve(tokens, env, command_line_no);
		n++;
	}
	free(command_lines);
	/*freeLinkedList(env);*/
	exit(exit_stat);
}
