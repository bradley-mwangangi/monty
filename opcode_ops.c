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
	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pall, stack empty\n", line_number);
		cleanup();
		exit(EXIT_FAILURE);
	}

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
	(void)line_number;

	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		cleanup();
		exit(EXIT_FAILURE);
	}
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
		cleanup();
		exit(EXIT_FAILURE);
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
