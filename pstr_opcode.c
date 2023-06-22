#include "monty.h"
/**
 * pstr - prints the string starting at the top
 * @counter: number
 * @head: head
 * Return: no return
*/
void pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
