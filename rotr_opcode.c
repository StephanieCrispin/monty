#include "monty.h"
/**
 * f_rotr- rotates the stack to the bottom
 * @stack: stack head
 * @line_number: line_number
 * Return: void
*/
void f_rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *duplicate;

	duplicate = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	while (duplicate->next)
	{
		duplicate = duplicate->next;
	}
	duplicate->next = *stack;
	duplicate->prev->next = NULL;
	duplicate->prev = NULL;
	(*stack)->prev = duplicate;
	(*stack) = duplicate;
}
