#include "monty.h"

/**
* addlst -> Adds an element to the last
* @stack_ptr: A pointer to the stack
* @push: The data with the push
*/
void addlst(stack_t **stack_ptr, int push)
{
	stack_t *new_val, *tail;

	tail = *stack_ptr;
	new_val = malloc(sizeof(stack_t));
	new_val->n = push;
	new_val->next = *stack_ptr;

	if (*stack_ptr == NULL)
	{
		new_val->prev = NULL;
		*stack_ptr = new_val;
		return;
	}

	while (tail->next != NULL)
		tail = tail->next;
	tail->next = new_val;
	new_val->prev - tail;
}
