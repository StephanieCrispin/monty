#include "monty.h"

/**
 * check_length-> Checks the length of a stack
 * @stack: The stack to be checked
 */

int check_length(stack_t *stack)
{
    int length = 0;

    while (stack)
    {
        stack = stack->next;
        length++;
    }
    return (length);
}