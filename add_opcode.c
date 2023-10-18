#include "monty.h"
/**
 * f_add -> Adds the top two int numbers on the stack and stores
 * their value in the second number of the stack which now becomes the first
 * @stack: The stack
 * @line_number: The line number
 */
void f_add(stack_t **stack, unsigned int line_number)
{
    int length = 0, result;
    stack_t *head_copy = *stack;

    while (head_copy)
    {
        head_copy = head_copy->next;
        length++;
    }

    if (length < 2)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    result = (*stack)->n + (*stack)->next->n;
    (*stack)->next->n = result;
    (*stack)->next->prev = NULL;
    *stack = (*stack)->next;
}
