#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @head: double pointer to the stack head
 * @counter: line number
 * Return: no return value
 */
void pop(stack_t **head, unsigned int counter)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	if ((*head)->next != NULL)
		(*head)->next->prev = NULL;

	temp = *head;
	*head = (*head)->next;
	free(temp);
}
