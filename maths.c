#include "monty.h"
/**
 * addmath - function to add
 * @stack: is thepointer to the stacks mem address
 * @line_num2: is the actual line number
 */
void addmath(stack_t **stack, unsigned int line_num2)
{
	stack_t *ptr_node;
	int counter = 0, add;

	ptr_node = *stack;
	while (ptr_node != NULL)
	{
		ptr_node = ptr_node->next;
		counter++;
	}
	if (counter < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num2);
		fclose(global.f_handler);
		free(global.monty_line);
		freePlates(*stack);
		exit(EXIT_FAILURE);
	}
	ptr_node = *stack;
	add = ptr_node->n + ptr_node->next->n;
	ptr_node->next->n = add;
	*stack = ptr_node->next;
	free(ptr_node);
}

/**
 * submath - function to subtract
 * @stack: pointer to the stack's mem location
 * @line_num2: the actualline number
 */
void submath(stack_t **stack, unsigned int line_num2)
{
	stack_t *ptr_node;
	int subt, counter = 0;

	ptr_node = *stack;
	while (ptr_node != NULL)
	{
		ptr_node = ptr_node->next;
		counter++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num2);
		fclose(global.f_handler);
		free(global.monty_line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	ptr_node = *stack;
	subt = ptr_node->next->n - ptr_node->n;
	ptr_node->next->n = subt;
	*stack = ptr_node->next;
	free(ptr_node);
}

/**
 * mulmath - function to multiply
 * @stack: pointer to the stacks memory location
 * @line_num2: the actual line num
 */
void mulmath(stack_t **stack, unsigned int line_num2)
{
	stack_ t *ptr_node;
	int mult, counter = 0;

	ptr_node = *stack;
	while (ptr_node != NULL)
	{
		ptr_node = ptr_node->next;
		counter++;
	}
	if (counter < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num2);
		fclose(global.f_handler);
		free(global.monty_line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	ptr_node = *stack;
	mult = ptr_node->next->n * ptr_node->n;
	ptr_node->next->n = mult;
	*stack = ptr_node->next;
	free(ptr_node);
}
/**
 * divmath - function to divide
 * @stack: pointer to the mem location
 * @line_num2: the actual line num
 */
void divmath(stack_t **stack, unsigned int line_num2)
{
	stack_t *ptr_node;
	int div_v, counter = 0;

	ptr_node = *stack;
	while (ptr_node != NULL)
	{
		ptr_node = ptr_node->next;
		counter++;
	}
	if (counter < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num2);
		fclose(global.f_handler);
		free(global.monty_line);
		freePlates(*stack);
		exit(EXIT_FAILURE);
	}
	ptr_node = *stack;
	if (ptr_node->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num2);
		fclose(global.f_handler);
		free(global.monty_line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	div_v = ptr_node->next->n / ptr_node->n;
	ptr_node->next->n = div;
	*stack = ptr_node->next;
	free(ptr_node);
}

/**
 * modmath - funtion to calculate the modulus
 * @stack: the pointer to the memory of the stack
 * @line_num2: the actual line number
 */
void modmath(stack_t **stack, unsigned int line_num2)
{
	stack_t *ptr_node;
	int div, counter = 0;

	ptr_node = *stack;
	while (ptr_node != NULL)
	{
		ptr_node = ptr_node->next;
		counter++;
	}
	if (counter < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num2);
		fclose(global.f_handler);
		free(global.monty_line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	ptr_node = *stack;
	if (ptr_node->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num2);
		fclose(global.f_handler);
		free(global.monty_line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	div = ptr_node->next->n % ptr_node->n;
	ptr_node->next->n = div;
	*stack = ptr_node->next;
	free(ptr_node);
}
