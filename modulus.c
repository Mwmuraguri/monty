#include "monty.h"

/**
 * f_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_mod(stack_t **head, unsigned int counter)
{
	stack_t *first = NULL, *second = NULL;
	int len = stack_len(*head);

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}

	first = *head;
	second = first->next;

	if (first->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		exit(EXIT_FAILURE);
	}

	second->n %= first->n;
	*head = second;
	(*head)->prev = NULL;

	free(first);
}

/**
 * stack_len - returns the number of elements in a stack.
 * @head: stack head
 * Return: number of elements in the stack
 */
int stack_len(stack_t *head)
{
	int count = 0;
	stack_t *current = head;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	return (count);
}
