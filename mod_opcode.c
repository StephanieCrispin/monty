#include "monty.h"
/**
 * f_mod - computes the modulus of second element and the top element
 * of the stack
 * @stack: the stack head
 * @line_number: line_number
 * Return: void
*/
void f_mod(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n % h->n;
	h->next->n = aux;
	*stack = h->next;
	free(h);
}
