#include "monty.h"
/**
 * f_sub -> Subtracts the first from the second element on the stack and stores
 * their value in the second number of the stack which now becomes the first
 * @stack: The stack
 * @line_number: The line number
 */
void f_sub(stack_t **stack, unsigned int line_number)
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
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    head_copy = *stack;

    result = head_copy->next->n - head_copy->n;
    head_copy->next->n = result;
    *stack = head_copy->next;
    free(head_copy);
}
