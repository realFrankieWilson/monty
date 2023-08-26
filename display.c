#include "monty.h"
/**
 * print_stack - print the stack like pall function
 * @stack: pointer to the mem direction of stack
 * @line_number: Number of actual line
 */
void print_stack(stack_t **stack, unsigned int line_number)

{
	stack_t *display_node = NULL;

	(void)line_number;

	if (!(stack == NULL || *stack == NULL))
	{
		display_node = *stack;
		while (display_node)
		{
			printf("%d\n", display_node->n);
			display_node = display_node->next;
		}
	}
}

/**
 * print_top - print the top element (pint)
 * @stack: pointer to the mem location of stack
 * @line_number: Number of actual line
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	int top = 0;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(global.f_handler);
		free(global.monty_line);
		freePlates(*stack);
		exit(EXIT_FAILURE);
	}
	top = (*stack)->n;
	printf("%d\n", top);
}

/**
 * printTopC - prints the top char (pchar)
 * @stack: pointer to the stack mem address
 * @line_number: is the current line number
 */
void printTopC(stack_t **stack, unsigned int line_number)
{
	stack_t *s_node = *stack;

	if (c_node == NULL)
	{
		fprintf(stderr, "L%d can't pchar, stack empty\n", line_number);
		fclose(global.f_handler);
		free(global.monty_line);
		freePlates(*stack);
		exit(EXIT_FAIILURE);
	}
	if (s_node->n > 127 || s_node->n < 0)
	{
		fprintf(stderr, "L%d can't pchar, stack empty\n", line_number);
		fclose(global.f_handler);
		free(global.monty_line);
		freePlates(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", s_node->n);
}

/**
 * printTops - print the top string (pstr)
 * @stack: pointer to the stack mem address
 * @line_number: is the current line number
 */
void printTops(stack_t **stack, unsigned int line_number)
{
	stack_t *top_node = *stack;
	(void)line_number;

	while (top_node != NULL)
	{
		if (top_node->n <= 0 || top_node->n > 127)
			break;
		printf("%c", top_node->n);
		top_node = top_node->next;
	}
	print("\n");
}
