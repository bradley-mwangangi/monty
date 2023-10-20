#include "monty.h"

/**
 * _rotl - rotates the stack to the top
 * top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one
 * @top: pointer to pointer of stack's top node
 * @line_number: current line's number
*/
void _rotl(stack_t **top, unsigned int line_number)
{
	stack_t *top_element, *last_element;
	(void)line_number;

	/* if stack is empty or stack has one element */
	if (*top == NULL || (*top)->next == NULL)
		return;

	top_element = *top;

	/* iterate to find last element */
	last_element = *top;
	while (last_element->next)
		last_element = last_element->next;

	/* top now points to second element */
	*top = top_element->next;
	(*top)->prev = NULL;

	top_element->next = NULL; /* top element points to null (stack bottom) */
	top_element->prev = last_element;
	last_element->next = top_element;
}

/**
 * _rotr - rotates the stack to the bottom
 * last element of the stack becomes the top element
 * @top: pointer to pointer of stack's top node
 * @line_number: current line's number
*/
void _rotr(stack_t **top, unsigned int line_number)
{
	stack_t *top_element, *last_element;
	(void)line_number;

	/* if stack is empty or stack has one element */
	if (*top == NULL || (*top)->next == NULL)
		return;

	top_element = *top;

	/* iterate to find last element */
	last_element = *top;
	while (last_element->next)
		last_element = last_element->next;

	/* second last element's *next points to null (stack bottom) */
	last_element->prev->next = NULL;

	/* last element's *next points to top element */
	last_element->next = top_element;
	top_element->prev = last_element;

	*top = last_element;
	(*top)->prev = NULL;
}
