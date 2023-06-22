#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
 * main - monty code interpreter
 * @argc: arguments
 * @argv: file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *cont;
	FILE *fl;
	size_t sz = 0;
	ssize_t readline = 1;
	stack_t *stack = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fl = fopen(argv[1], "r");
	bus.file = fl;
	if (!fl)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (readline > 0)
	{
		cont = NULL;
		readline = getline(&cont, &sz, fl);
		bus.content = cont;
		count++;
		if (readline > 0)
		{
			execute(cont, &stack, count, fl);
		}
		free(cont);
	}
	free_stack(stack);
	fclose(fl);
	return (0);
}
