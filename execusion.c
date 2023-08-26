#include "monty.h"

/**
* push_value-> Executes the push function
* @stack_ptr: A pointer to the stack memory address
* @l_num: The current line number
*/
void push_value(stack_t **stack_ptr, unsigned int l_num)
{
	int push, idx = 0;
	if (global.data_ptr == NULL)
	{
		fprintf(stderr, "L%d: Usage: push integer\n", l_num);
		exit(EXIT_FAILURE);
	}

	if(global.data_ptr[0] == '-')
		idx++;
	for (; global.data_ptr[idx] != '\0'; idx++)
	{
		if (isdigit(global.data_ptr[idx]) == 0)
		{
			fclose(global.f_handler);
			free(global.monty_line);
			free_stack(*stack_ptr);
			exit(EXIT_FAILURE);
		}
	}

	push = atoi(global.data_ptr);
	if (global.data_ptr == 0)
		addtp(stack_ptr, push);
	else
		addlst(stack_ptr, push);
}



/**
* add_top -> Adds an element to the top of the stack
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
		exit (0);

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

