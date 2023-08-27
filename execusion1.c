#include "monty.h"

/**
* queue_f -> A queue function to describe a data struct
* @stack_ptr: The pointer to the stack memory address
* @l_num: The current line number
*
* Return: Nothing
*/
void queue_f(stack_t **stack_ptr, unsigned int l_num)
{
	(void)stack_ptr;
	(void)l_num;
	global.data_ptr = 0;
}



/**
* stack_f -> A function that describes a data struct
* @stack_ptr: A pointer to the stack memory address
* @l_num: The current line number.
*
* Return: Nothing
*/
void stack_f(stack_t **stack_ptr, unsigned int l_num)
{
	(void)stack_ptr;
	(void)l_num;
	global.data_string = 1;
}



/**
* swaptp -> Changes the order into the top elements
* @stack_ptr: The pointer to stack memory address
* @l_num: The current line number
*/
void swaptp(stack_t **stack_ptr, unsigned int l_num)
{
	stack_t *tmp;
	int len = 0, swap;

	tmp = *stack_ptr;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short"N, l_num);
		fclose(global.f_handler);
		free(global.monty_line);
		free_stack(*stack_ptr);
		exit(EXIT_FAILURE);
	}
	tmp = *stack_ptr;
	swap = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = swap;
}



/**
* rotatetp -> Rotates top of the stack
* @stack_ptr: The pointer to the stack memory address
* @l_num: Unused
*
* Return: Nothing
*/
void rotatetp(stack_t **stack_ptr, __attribute__((unused)) unsigned int l_num)
{
	stack_t *new_node = *stack_ptr, *tmp;

	if (*stack_ptr == NULL || (*stack_ptr)->next == NULL)
		return;
	tmp = (*stack_ptr)->next;
	tmp->prev = NULL;
	while (new_node != NULL)
		new_node = new_node->next;

	new_node->next = *stack_ptr;
	(*stack_ptr)->next = NULL;
	(*stack_ptr)->prev = new_node;
	(*stack_ptr) = tmp;
}




/**
 * rotatebtm -> Rotates top bottom of the stack
 * @stack_ptr: The pointer to stack memory address
 * @l_num: Current line number
 *
 * Return: Nothing
 */
void rotatebtm(stack_t **stack_ptr, unsigned int l_num)
{
	stack_t *new_node = *stack_ptr;
	(void)l_num;

	if (*stack_ptr == NULL || (*stack_ptr)->next == NULL)
		return;

	while (new_node->next)
		new_node = new_node->next;

	new_node->next = *stack_ptr;
	new_node->prev->next = NULL;
	new_node->prev = NULL;
	(*stack_ptr)->prev = new_node;
	(*stack_ptr) = new_node;
}
