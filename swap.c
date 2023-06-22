#include "monty.h"

/**
 * free_stack - frees a stack
 * @head: pointer to the stack head
 * Return: no return value
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}


/**
 * swap - swaps the top two elements of the stack
 * @head: double pointer to the stack head
 * @counter: line number
 * Return: no return value
 */
void swap(stack_t **head, unsigned int counter)
{
	int temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = temp;
}
