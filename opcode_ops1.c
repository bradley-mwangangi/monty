#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @top: pointer to pointer of stack's top node
 * @line_number: current line's number
*/
void _add(stack_t **top, unsigned int line_number)
{
	stack_t *first_element, *second_element;
	(void)line_number;

	if (top == NULL)
		cleanup_and_exit_failure();

	/* if stack is empty or stack has one element */
	if (*top == NULL || (*top)->next == NULL)
		err_stack_too_short("add");

	first_element = *top;
	second_element = (*top)->next;

	second_element->n += first_element->n;

	(*top) = second_element;
	(*top)->prev = NULL;

	free(first_element);
}

/**
 * _nop - doesn't do anything
 * @top: pointer to pointer of stack's top node
 * @line_number: current line's number
*/
void _nop(stack_t **top, unsigned int line_number)
{
	(void)top;
	(void)line_number;
}

/**
 * _sub - subtracts the top element of the stack from the second top
 * @top: pointer to pointer of stack's top node
 * @line_number: current line's number
*/
void _sub(stack_t **top, unsigned int line_number)
{
	stack_t *first_element, *second_element;
	(void)line_number;

	if (top == NULL)
		cleanup_and_exit_failure();

	/* if stack is empty or stack has one element */
	if (*top == NULL || (*top)->next == NULL)
		err_stack_too_short("sub");

	first_element = *top;
	second_element = (*top)->next;

	second_element->n -= first_element->n;

	(*top) = second_element;
	(*top)->prev = NULL;

	free(first_element);
}

/**
 * _div - divides the second top element of the stack by the top
 * @top: pointer to pointer of stack's top node
 * @line_number: current line's number
*/
void _div(stack_t **top, unsigned int line_number)
{
	stack_t *first_element, *second_element;
	(void)line_number;

	if (top == NULL)
		cleanup_and_exit_failure();

	/* if stack is empty or stack has one element */
	if (*top == NULL || (*top)->next == NULL)
		err_stack_too_short("div");

	first_element = *top;
	second_element = (*top)->next;

	if (first_element->n == 0)
		err_division_by_zero();

	second_element->n /= first_element->n;

	(*top) = second_element;
	(*top)->prev = NULL;

	free(first_element);
}

/**
 * _mul - multiplies the second top element of the stack with the top element
 * @top: pointer to pointer of stack's top node
 * @line_number: current line's number
*/
void _mul(stack_t **top, unsigned int line_number)
{
	stack_t *first_element, *second_element;
	(void)line_number;

	if (top == NULL)
		cleanup_and_exit_failure();

	/* if stack is empty or stack has one element */
	if (*top == NULL || (*top)->next == NULL)
		err_stack_too_short("mul");

	first_element = *top;
	second_element = (*top)->next;

	second_element->n *= first_element->n;

	(*top) = second_element;
	(*top)->prev = NULL;

	free(first_element);
}
