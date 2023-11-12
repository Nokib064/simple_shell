#include "shell.h"

/**
 * freeLinkedList - frees the memory allocated for the linked list
 * @head: pointer to the head of the linked list
 * Return: Nothing
 */
void freeLinkedList(list_s *head)
{
	list_s *current = head;
	list_s *next;

	while (current != NULL)
	{
		next = current->next;
		current = next;
		free(current->var);
		free(current);
		/*current = next;*/
	}
}

#include "shell.h"
/**
 * db_ptr_free - free malloced arrays
 * @arr_str: array of strings
 * Return: Nothing
 */
void db_ptr_free(char **arr_str)
{
	int a = 0;

	while (arr_str[a] != NULL)
	{
		free(arr_str[a]);
		a++;
	}
	/*free(arr_str);*/
}


#include "shell.h"
/**
 * _strlen - return length of a string
 * @s: string
 * Return: 0
 */
int _strlen(char *s)
{
	int count = 0;
	int i;

	for (i = 0; s[i] != '\0'; i++)

		count++;


	return (count);
}
#include "shell.h"
/**
 * custom_malloc - allocates memory and set all values to zero
 * @prev_mem_ptr: pointer to the memory previously allocated (malloc(old_size))
 * @prev_size: size previously allocated
 * @new__size: new size to reallocate
 * Return: pointer to reallocate
 */

void *custom_malloc(void *prev_mem_ptr, unsigned int prev_size,
		unsigned int new__size)
{
	void *p;
	unsigned int i;

	if (new__size == 0 && prev_mem_ptr != NULL)
	{
		free(prev_mem_ptr);
		return (NULL);
	}

	if (new__size == prev_size)
		return (prev_mem_ptr);

	if (prev_mem_ptr == NULL)
	{
		p = malloc(new__size);
		if (p == NULL)
			return (NULL);
		else
			return (p);
	}

	p = malloc(new__size);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < prev_size && i < new__size; i++)
		*((char *)p + i) = *((char *)prev_mem_ptr + i);
	free(prev_mem_ptr);

	return (p);
}
