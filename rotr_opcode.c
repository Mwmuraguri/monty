#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @head: stack head
 * @counter: line number
 * Return: no return
 */
void rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy, *last;

	if (*head == NULL || (*head)->next == NULL)
		return;

	copy = *head;
	last = *head;

	while (last->next != NULL)
		last = last->next;

	last->next = copy;
	copy->prev = last;
	*head = copy->next;
	(*head)->prev = NULL;
	copy->next = NULL;
}
