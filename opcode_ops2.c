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

/**
 * _stack - sets format of the data to a stack (LIFO)
 * @top: pointer to pointer of stack's top node
 * @line_number: current line's number
*/
void _stack(stack_t **top, unsigned int line_number)
{
	(void)top;
	(void)line_number;

	globals.isStack = true;
}

/**
 * _queue - sets format of the data to a _queue (FIFO)
 * @top: pointer to pointer of stack's top node
 * @line_number: current line's number
*/
void _queue(stack_t **top, unsigned int line_number)
{
	(void)top;
	(void)line_number;

	globals.isStack = false;
}

/**
 * _pchar - prints the char at the top of the stack
 * followed by a new line
 * @top: pointer to pointer of stack's top node
 * @line_number: current line's number
*/
void _pchar(stack_t **top, unsigned int line_number)
{
	int value;

	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		cleanup_and_exit_failure();
	}

	value = (*top)->n;
	if (value >= 0 && value <= 127)
	{
		printf("%c\n", value);
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		cleanup_and_exit_failure();
	}
}

/**
 * _pstr - prints the string starting at the top of the stack,
 * followed by a new line
 * @top: pointer to pointer of stack's top node
 * @line_number: current line's number
*/
void _pstr(stack_t **top, unsigned int line_number)
{
	stack_t *current;
	int value;
	(void)line_number;

	if (*top == NULL)
	{
		printf("\n");
		return;
	}

	current = *top;
	while (current)
	{
		value = current->n;
		if (value == 0 || value < 0 || value > 127)
			break;

		printf("%c", value);
		current = current->next;
	}
	printf("\n");
}
