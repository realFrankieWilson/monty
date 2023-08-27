#include "monty.h"

/**
* push_value-> Executes the push function
* @stack_ptr: A pointer to the stack memory address
* @l_num: The current line number
*/
void push_value(stack_t **stack_ptr, unsigned int l_num)
{
	int push, idx = 0;

	if (global.data_ptr != NULL)
	{
		if (global.data_ptr[0] == '-')
			idx++;
		for (; global.data_ptr[idx] != '\0'; idx++)
		{
			if (isdigit(global.data_ptr[idx]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer"N, l_num);
				fclose(global.f_handler);
				free(global.monty_line);
				free_stack(*stack_ptr);
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer"N, l_num);
		fclose(global.f_handler);
		free(global.monty_line);
		free_stack(*stack_ptr);
		exit(EXIT_FAILURE);
	}
	push = atoi(global.data_ptr);
	if (global.data_string == 0)
	{
		addtp(stack_ptr, push);
	}
	else
	{
		addlst(stack_ptr, push);
	}
}



/**
* addtp -> Adds an element to the top of the stack
* @stack_ptr: A pointer to the stack memory address
* @push: The data argument to push
* Return: Nothing
*/
void addtp(stack_t **stack_ptr, int push)
{
	stack_t *front = *stack_ptr;
	stack_t *new_val;

	new_val = malloc(sizeof(stack_t));
	if (new_val == NULL)
		exit(0);

	if (front == NULL)
	{
		new_val->n = push;
		new_val->next = *stack_ptr;
		new_val->prev = NULL;
		*stack_ptr = new_val;
	}
	else
		front->prev = new_val;
}



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
	if (new_val == NULL)
		malloc_failed();

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



/**
* delett -> Delete the top of an element
* @stack_ptr: The pointer to the stack memory address
* @l_num: The current line number
*/
void delett(stack_t **stack_ptr, unsigned int l_num)
{
	stack_t *rem;

	if (stack_ptr == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack"N, l_num);
		fclose(global.f_handler);
		free(global.monty_line);
		free_stack(*stack_ptr);
		exit(EXIT_FAILURE);
	}
	rem = *stack_ptr;
	*stack_ptr = rem->next;
	free(rem);
}



/**
* nop -> do nothing
* @stack_ptr: A stack pointer to memory address
* @l_num: The current line number
*/
void nop(stack_t **stack_ptr, unsigned int l_num)
{
	(void)*stack_ptr;
	(void)l_num;
}
