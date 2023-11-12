#include "shell.h"
/**
 * environ_list - creates a linked list from environmental variables
 * @env_var: environmental variables
 * Return: linked list
 */
list_s *environ_list(char *env_var)
{
	list_s *h = NULL;
	int i;

	for (i = 0; env_var[i] != '\0'; i++)
	{
		Add_NodeToEnd(&h, &env_var[i]);
	}

	return (h);
}

#include "shell.h"
/**
 * LinkedList - prints the linked list and returns its size
 * @Head: pointer to the head of the linked list
 * Return: size of the linked list
 */
size_t LinkedList(list_s *Head)
{
	list_s *current = Head;
	size_t count = 0;

	while (current != NULL)
	{
		if (current->var == NULL)
		{
			write(STDOUT_FILENO, "(nil)", 5);
			write(STDOUT_FILENO, "\n", 1);
		}
		else
		{
			write(STDOUT_FILENO, current->var, strlen(current->var));
			write(STDOUT_FILENO, "\n", 1);
		}
		current = current->next;
		count++;
	}
	return (count);
}

#include "shell.h"
/**
 * Add_NodeToEnd - adds a new node to the end of the linked list
 * @Head: double pointer to head of the linked list
 * @str: new node data
 * Return: pointer to the new linked list
 */
list_s *Add_NodeToEnd(list_s **Head, char *str)
{
	list_s *newNode;

	if (Head == NULL || str == NULL)
		return (NULL);

	newNode = malloc(sizeof(list_s));

	if (newNode == NULL)
		return (NULL);

	newNode->var = _strdup(str);
	newNode->next = NULL;

	if (*Head == NULL)
	{
		*Head = newNode;
	}
	else
	{
		list_s *temp = *Head;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}

	return (*Head);
}

#include "shell.h"
/**
 * Delete_NodeAtIndex - deletes a node at the specified index
 * @Head: double pointr to head of the linked list
 * @index: index of the node to be deleted
 * Return: 1 if successful, otherwise -1
 */
int Delete_NodeAtIndex(list_s **Head, int index)
{
	list_s *temp, *prev, *current;
	int count;

	if (*Head == NULL || index < 0)
		return (-1);

	if (index == 0)
	{
		temp = *Head;
		*Head = temp->next;
		free(temp->var);
		free(temp);
		return (1);
	}

	prev = NULL;
	current = *Head;
	count = 0;

	while (current != NULL && count != index)
	{
		prev = current;
		current = current->next;
		count++;
	}

	if (current == NULL)
		return (-1);

	prev->next = current->next;
	free(current->var);
	free(current);
	return (1);
}

