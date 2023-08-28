/****The Functions on this file perform some basic maths****/

#include "monty.h"

/**
* addmath -> perform addition
* @stack_ptr: The pointer to stack memory address
* @l_num: The current line number
*
* Return: Nothing
*/
void addmath(stack_t **stack_ptr, unsigned int l_num)
{
	stack_t *new_node;
	int len = 0, add;

	new_node = *stack_ptr;
	while (new_node != NULL)
	{
		new_node = new_node->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short"N, l_num);
		fclose(global.f_handler);
		free(global.monty_line);
		free_stack(*stack_ptr);
		exit(EXIT_FAILURE);
	}

	new_node = *stack_ptr;
	add = new_node->n + new_node->next->n;
	new_node->next->n = add;
	*stack_ptr = new_node->next;
	free(new_node);
}



/**
* submath -> perform subtraction
* @stack_ptr: The pointer to stack memory address
* @l_num: The current line number
*
* Return: Nothing
*/
void submath(stack_t **stack_ptr, unsigned int l_num)
{
	stack_t *new_node;
	int len = 0, sub;

	new_node = *stack_ptr;
	while (new_node != NULL)
	{
		new_node = new_node->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short"N, l_num);
		fclose(global.f_handler);
		free(global.monty_line);
		free_stack(*stack_ptr);
		exit(EXIT_FAILURE);

	}

	sub = new_node->next->n - new_node->n;
	new_node->next->n = sub;
	*stack_ptr = new_node->next;
	free(new_node);
}



/**
* mulmath -> perform multiplication
* @stack_ptr: The pointer to stack memory address
* @l_num: The current line number
*
* Return: Nothing
*/
void mulmath(stack_t **stack_ptr, unsigned int l_num)
{
	stack_t *new_node;
	int len = 0, mul;

	new_node = *stack_ptr;
	while (new_node != NULL)
	{
		new_node = new_node->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short"N, l_num);
		fclose(global.f_handler);
		free(global.monty_line);
		free_stack(*stack_ptr);
		exit(EXIT_FAILURE);

	}

	mul = new_node->next->n * new_node->n;
	new_node->next->n = mul;
	*stack_ptr = new_node->next;
	free(new_node);
}



/**
* divmath -> perform division
* @stack_ptr: The pointer to stack memory address
* @l_num: The current line number
*
* Return: Nothing
*/
void divmath(stack_t **stack_ptr, unsigned int l_num)
{
	stack_t *new_node;
	int len = 0, div;

	new_node = *stack_ptr;
	while (new_node != NULL)
	{
		new_node = new_node->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short"N, l_num);
		fclose(global.f_handler);
		free(global.monty_line);
		free_stack(*stack_ptr);
		exit(EXIT_FAILURE);

	}

	div = new_node->next->n / new_node->n;
	new_node->next->n = div;
	*stack_ptr = new_node->next;
	free(new_node);
}



/**
* modmath -> perform modular operation
* @stack_ptr: The pointer to stack memory address
* @l_num: The current line number
*
* Return: Nothing
*/
void modmath(stack_t **stack_ptr, unsigned int l_num)
{
	stack_t *new_node;
	int len = 0, mod;

	new_node = *stack_ptr;
	while (new_node != NULL)
	{
		new_node = new_node->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short"N, l_num);
		fclose(global.f_handler);
		free(global.monty_line);
		free_stack(*stack_ptr);
		exit(EXIT_FAILURE);

	}

	if (new_node->n == 0)
	{
		fprintf(stderr, "L%d: division by zero"N, l_num);
		fclose(global.f_handler);
		free(global.monty_line);
		free_stack(*stack_ptr);
		exit(EXIT_FAILURE);

	}

	mod = new_node->next->n % new_node->n;
	new_node->next->n = mod;
	*stack_ptr = new_node->next;
	free(new_node);
}
