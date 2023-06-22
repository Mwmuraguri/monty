#include "monty.h"

/**
 * f_sub - subtraction
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *aux, *first, *second;
	int sus, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	first = *head;
	second = first->next;
	sus = second->n - first->n;
	second->n = sus;

	*head = second;
	(*head)->prev = NULL;

	free(first);
}
