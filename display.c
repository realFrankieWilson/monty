#include "monty.h"

/**
 * print_stk -> print the stack like pall function
 * @stack_ptr: pointer to the mem direction of stack
 * @l_num: Number of actual line
 *
 * Return: Nothing
 */
void print_stk(stack_t **stack_ptr, unsigned int l_num)

{
	stack_t *display_node = NULL;
	(void)l_num;

	if (!(stack_ptr == NULL || *stack_ptr == NULL))
	{
		display_node = *stack_ptr;

		while (display_node)
		{
			printf("%d"N, display_node->n);
			display_node = display_node->next;
		}
	}
}



/**
 * print_tp -> print the top element (pint)
 * @stack_ptr: pointer to the mem location of stack
 * @l_num: Number of actual line
 *
 * Return: Nothing
 */
void print_tp(stack_t **stack_ptr, unsigned int l_num)
{
	if (!(*stack_ptr))
	{
		fprintf(stderr, "L%u: can't pint, stack empty"N, l_num);
		fclose(global.f_handler);
		free(global.monty_line);
		free_stack(*stack_ptr);
		exit(EXIT_FAILURE);
	}
	printf("%d"N, (*stack_ptr)->n);
}



/**
 * pchar -> prints the top char (pchar)
 * @stack_ptr: pointer to the stack mem address
 * @l_num: is the current line number
 *
 * Return: Nothin
 */
void pchar(stack_t **stack_ptr, unsigned int l_num)
{
	stack_t *s_node = *stack_ptr;

	if (s_node)
	{
		fprintf(stderr, "L%d can't pchar, stack empty"N, l_num);
		fclose(global.f_handler);
		free(global.monty_line);
		free_stack(*stack_ptr);
		exit(EXIT_FAILURE);
	}
	if (s_node->n > 127 || s_node->n < 0)
	{
		fprintf(stderr, "L%d can't pchar, stack empty"N, l_num);
		fclose(global.f_handler);
		free(global.monty_line);
		free_stack(*stack_ptr);
		exit(EXIT_FAILURE);
	}
	printf("%c"N, s_node->n);
}



/**
 * pstr - print the top string (pstr)
 * @stack_ptr: pointer to the stack mem address
 * @l_num: is the current line number
 *
 * Return: Nothing
 */
void pstr(stack_t **stack_ptr, unsigned int l_num)
{
	stack_t *top_node = *stack_ptr;
	(void)l_num;

	while (!top_node)
	{
		if (top_node->n <= 0 || top_node->n > 127)
			break;
		printf("%c", top_node->n);
		top_node = top_node->next;
	}
	printf(N);
}
