#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp, *first;

	if (*head == NULL || (*head)->next == NULL)
		return;

	tmp = *head;
	first = *head;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = first;
	first->prev = tmp;
	*head = first->next;
	(*head)->prev = NULL;
	first->next = NULL;
}

