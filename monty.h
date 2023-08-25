#ifndef MONTY_H
#define MONTY_H




/******************* STANDARD LIBRARY ******************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>




/******************** STRUCTURES DECLARATIONS*******************
 * struct stac_s -> doubly linked list representation of a stack
 * @n: integer
 * @prev: points to the previouse element of the stack or queue
 * @next: points to the next element of the stack or queue
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instructions_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



/******************* GLOBAL OPCODES **********************/
extern char **op_value;


/******************** CODE FUNCTIONS ***********************/








#endif /*MONTY*/
