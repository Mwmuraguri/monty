#include "monty.h"

/**
 * f_div - divides the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_div(stack_t **head, unsigned int counter)
{
	stack_t *first = NULL, *second = NULL;
	int len = stack_len(*head);

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}

	first = *head;
	second = first->next;

	if (first->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		exit(EXIT_FAILURE);
	}

	second->n /= first->n;
	*head = second;
	(*head)->prev = NULL;

	free(first);
}
