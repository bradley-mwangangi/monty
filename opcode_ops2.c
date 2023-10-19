#include "monty.h"

/**
 * _mod - computes the rest of the division of the second top element
 * of the stack by the top
 * @top: pointer to pointer of stack's top node
 * @line_number: current line's number
*/
void _mod(stack_t **top, unsigned int line_number)
{
	stack_t *first_element, *second_element;
	(void)line_number;

	if (top == NULL)
		cleanup_and_exit_failure();

	/* if stack is empty or stack has one element */
	if (*top == NULL || (*top)->next == NULL)
		err_stack_too_short("mod");

	first_element = *top;
	second_element = (*top)->next;

	if (first_element->n == 0)
		err_division_by_zero();

	second_element->n %= first_element->n;

	(*top) = second_element;
	(*top)->prev = NULL;

	free(first_element);
}
