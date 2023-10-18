#include "monty.h"

/**
 * f_mul - multiply top two elements of the stack.
 * @stack: stack head
 * @line_number: line_number
 * Return: nothing
*/
void f_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	int length = 0, aux;

	h = *stack;
	while (h)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	aux = h->next->n * h->n;
	h->next->n = aux;
	*stack = h->next;
	free(h);
}
