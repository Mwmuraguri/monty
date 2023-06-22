#include "monty.h"

/**
 * f_pint - prints the top element of the stack
 * @head: pointer to the stack's head
 * @counter: line number
 */
void f_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
