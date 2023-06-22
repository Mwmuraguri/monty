#include "monty.h"

/**
 * queue - sets the stack mode to queue (FIFO)
 * @head: stack head
 * @counter: line number
 * Return: no return
 */
void queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * addqueue - adds a new node to the tail of the stack (queue mode)
 * @head: head of the stack
 * @n: new value
 * Return: no return
 */
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *last;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return;
	}

	last = *head;
	while (last->next != NULL)
		last = last->next;

	last->next = new_node;
	new_node->prev = last;
}
