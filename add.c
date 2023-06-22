#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void add(stack_t **head, unsigned int counter)
{
	stack_t *first, *second;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	first = *head;
	second = (*head)->next;

	second->n += first->n;

	*head = second;
	(*head)->prev = NULL;
	free(first);
}
