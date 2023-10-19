#include <ctype.h>
#include "monty.h"

/**
 * _push - pushes a node to top of the stack
 * @top: pointer to pointer of stack's top node
 * @line_number: current line's number
*/
void _push(stack_t **top, unsigned int line_number)
{
	int i, value;
	(void)line_number;

	if (!globals.arg)
		err_usage();

	for (i = 0; globals.arg[i] != '\0'; i++)
	{
		if (!isdigit(globals.arg[i]) && globals.arg[i] != '-')
			err_usage();
	}

	value = atoi(globals.arg);

	if (globals.isStack)
		add_dnodeint(top, value);
	else
	    add_dnodeint_end(top, value);
}

/**
 * _pall - prints all values in the stack
 * @top: pointer to pointer of stack's top node
 * @line_number: current line's number
*/
void _pall(stack_t **top, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *top;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * _pint - prints the value at the top of the stack
 * followed by a new line
 * @top: pointer to pointer of stack's top node
 * @line_number: current line's number
*/
void _pint(stack_t **top, unsigned int line_number)
{
	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		cleanup_and_exit_failure();
	}
	printf("%d\n", (*top)->n);
}

/**
 * _pop - removes the top element of the stack
 * @top: pointer to pointer of stack's top node
 * @line_number: current line's number
*/
void _pop(stack_t **top, unsigned int line_number)
{
	stack_t *popped;

	if (top == NULL || *top == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		cleanup_and_exit_failure();
	}

	popped = *top;
	if ((*top)->next)
	{
		*top = (*top)->next;
		(*top)->prev = NULL;
	}
	else
		*top = NULL;

	free(popped);
}

/**
 * _swap - swaps the top two elements of the stack
 * @top: pointer to pointer of stack's top node
 * @line_number: current line's number
*/
void _swap(stack_t **top, unsigned int line_number)
{
	stack_t *first_element, *second_element;
	(void)line_number;

	if (top == NULL)
		cleanup_and_exit_failure();

	/* if stack is empty or stack has one element */
	if (*top == NULL || (*top)->next == NULL)
		err_stack_too_short("swap");

	first_element = *top;
	second_element = (*top)->next;

	/* perform swapping */
	first_element->prev = second_element;
	first_element->next = second_element->next;

	/* if exists, update third element->prev to point to first element */
	if (second_element->next)
		second_element->next->prev = first_element;

	(*top) = second_element;
	(*top)->prev = NULL;
	(*top)->next = first_element;
}
