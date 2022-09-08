#ifndef MONTY_H
#define MONTY_H
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
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
 * struct instruction_s - opcode and its function
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

/**
* struct glob - Structure for global variable
* @Line_buffer: Result of getline on file.
* @file: File to read.
*/
typedef struct glob
{
	char *Line_buffer;
	FILE *file;
} global_t;

/*helper functions*/
void error_message(char *message, char *arg, stack_t **stack);
short _isnumber(char *str);
size_t length_stack(const stack_t *head);
void free_all(stack_t **stack);

/*functions*/
void push_stack(stack_t **stack, unsigned int line_number);
void push_queues(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void check_opc(char *, instruction_t (*o)[], int, stack_t **);
#endif /* _MONTY_H */
