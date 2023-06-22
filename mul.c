#include "monty.h"

/**
 * f_mul - multiplies the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *first = NULL, *second = NULL;
	int len = stack_len(*head);

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}

	first = *head;
	second = first->next;

	second->n *= first->n;
	*head = second;
	(*head)->prev = NULL;

	free(first);
}
