#include "monty.h"

/**
 * pall -> print the stack like pall function
 * @stack_ptr: pointer to the mem direction of stack
 * @l_num: Number of actual line
 *
 * Return: Nothing
 */
void pall(stack_t **stack_ptr, unsigned int l_num)

{
	stack_t *display_node = NULL;

	(void)l_num;

	if (!(stack_ptr == NULL || *stack_ptr == NULL))
	{
		display_node = *stack_ptr;
		while (display_node)
		{
			printf("%d\n", display_node->n);
			display_node = display_node->next;
		}
	}
}



/**
 * pint -> print the top element (pint)
 * @stack_ptr: pointer to the mem location of stack
 * @l_num: Number of actual line
 *
 * Return: Nothing
 */
void pint(stack_t **stack_ptr, unsigned int l_num)
{
	int top = 0;

	if (stack_ptr == NULL || *stack_ptr == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", l_num);
		fclose(global.f_handler);
		free(global.monty_line);
		free_stack(*stack_ptr);
		exit(EXIT_FAILURE);
	}
	top = (*stack_ptr)->n;
	printf("%d\n", top);
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

	if (s_node == NULL)
	{
		fprintf(stderr, "L%d can't pchar, stack empty\n", l_num);
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
	printf("%c\n", s_node->n);
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

	while (top_node != NULL)
	{
		if (top_node->n <= 0 || top_node->n > 127)
			break;
		printf("%c", top_node->n);
		top_node = top_node->next;
	}
	printf(N);
}
