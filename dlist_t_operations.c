#include "monty.h"

/**
 * add_dnodeint - adds a new node to top of stack (or start of queue)
 * @head: pointer to head pointer of the stack (or queue)
 * @n: value of the new node
 *
 * Return: address of new node or NULL on failure
*/
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		cleanup();

		exit(EXIT_FAILURE);
	}

	/**
	 * if stack or queue is not empty
	 * top (head) node's prev pointer is set to point to new node
	*/
	if (*head != NULL)
		(*head)->prev = new;

	new->n = n;
	new->prev = NULL;
	new->next = *head;

	*head = new;

	return (*head);
}

/**
 * add_dnodeint_end - adds a new node at the end of a stack or queue
 * @head: pointer to head pointer of the stack (or queue)
 * @n: value of the new node
 *
 * Return: address of new node or NULL on failure
*/
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new, *current;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		cleanup();

		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;
	new->next = NULL; /* as this will be last node */

	/**
	 * if *head is NULL, list is empty
	 * set *head to point to new
	 */
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	current = *head;
	while ((current)->next)
		current = current->next;

	current->next = new;
	new->prev = current;

	return (new);
}

/**
 * free_dlistint - frees a stack or a queue
 * @head: pointer to head node of the stack or queue
 *
 * Return: void
*/
void free_dlistint(stack_t *head)
{
	if (head == NULL)
		return;

	while (head->next)
	{
		head = head->next;
		free(head->prev);
	}
	free(head);
}
