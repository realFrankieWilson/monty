#ifndef MONTY_H
#define MONTY_H




/******************* STANDARD LIBRARY ******************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <fcntl.h>




/***************** MACROS *************************************/
#define DEL "\t\n"

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
 * struct global_rep -> Global representation
 * @data: integer
 * @prev_st: points to the previous element of the stack (or queue)
 * @next_st: points to the next element of the stack (or queue)
 * @flag_q: checks for queue
 * @data_ptr: ....
 */
typedef struct global_s
{
	char *data_ptr;
	FILE *f_handler;
	char *monty_line;
	int data_string;
} global_rep;


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
extern global_rep global;


/******************** CODE FUNCTIONS ***********************/
int op_select_fun(char *, stack_t **, unsigned int, FILE *);
void push_value(stack_t **, unsigned int);
void addtp(stack_t **, int);
void addlst(stack_t **, int);


/******************** ERROR MESSAGES ***********************/
int malloc_failed(void);
void free_stack(stack_t *);


#endif /*MONTY*/
