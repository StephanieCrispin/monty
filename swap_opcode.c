#include "monty.h"
/**
 * f_swap -> Swaps the first two elements on the list,
 * if the elements are less than 2 , it prints out an error message
 * @stack: The stack to be operated on
 * @line_number: The line number
 */
void f_swap(stack_t **stack, unsigned int line_number)
{

    stack_t *head_copy = *stack;
    int length = 0, auxilary;

    /*Loop through to the end of the stack*/
    for (; head_copy != NULL; length++)
        head_copy = head_copy->next;

    if (length < 2)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        fclose(bus.file);
        free(bus.content);
        /*Replace this with the function he has declared to free the stack if he has defined it already*/
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    auxilary = head_copy->n;
    head_copy->n = head_copy->next->n;
    head_copy->next->n = auxilary;
}