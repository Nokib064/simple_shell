#include "shell.h"

/**
 * db_ptr_free - free malloced arrays
 * @str: array of strings
 */
void db_ptr_free(char **str)
{
	int i = 0;

	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

#include "shell.h"

/**
 * printList - _print linked list
 * @h: linked list
 * Return: size of linked list
 */
size_t printList(list_s *h)
{
	list_s *c_list = h;
	int count = 0;
	int a = 0;

	if (h == NULL)
		return (0);
	while (c_list != NULL)
	{
		if (c_list->var == NULL)
		{
			write(STDOUT_FILENO, "(nil)", 5);
			write(STDOUT_FILENO, "\n", 1);
		}
		else
		{
			a = 0;
			while ((c_list->var)[a] != '\0')
				a++;
			write(STDOUT_FILENO, c_list->var, a);
			write(STDOUT_FILENO, "\n", 1);
		}
		c_list = c_list->next;
		count++;
	}
	return (count);
}

#include "shell.h"
/**
 * addNode_atEnd - add node to end of linked list
 * @h: pointer to head of linked list
 * @str: data to new node
 * Return: pointer to new linked list
 */
list_s *addNode_atEnd(list_s **h, char *str)
{
	list_s *new;
	list_s *holder;

	if (h == NULL || str == NULL)
		return (NULL);
	new = malloc(sizeof(list_s));
	if (new == NULL)
		return (NULL);

	new->var = _strdup(str);
	new->next = NULL;

	holder = *h;
	if (holder != NULL)
	{
		while (holder->next != NULL)
		{
			holder = holder->next;
		}
		holder->next = new;
	}
	else
	{
		*h = new;
	}
	return (*h);
}


#include "shell.h"
/**
 * deleteNode_atIndex - removing node at index
 * @h: input head address
 * @index: input index
 * Return: 1 if success, -1 if fail
 */
int deleteNode_atIndex(list_s **h, int index)
{
	list_s *head;
	list_s *holder;
	int counter = 0;

	if (*h == NULL)
		return (-1);
	if (index == 0)
	{
		holder = (*h)->next;
		free((*h)->var);
		free(*h);
		*h = holder;
		return (1);
	}
	counter = 1;
	head = *h;
	while (counter < index)
	{
		if (head == NULL)
			return (-1);
		head = head->next;
		counter++;
	}
	holder = head->next;
	head->next = holder->next;
	free(holder->var);
	free(holder);
	return (1);
}
#include "shell.h"
/**
 * free_linkedList - frees linked list
 * @list: linked list
 */
void free_linkedList(list_s *list)
{
	list_s *holder;

	while (list != NULL)
	{
		holder = list;
		list = list->next;
		free(holder->var);
		free(holder);
	}

}
