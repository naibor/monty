#include "monty.h"
global_t the_global;
/**
 * main - Entry point
 *
 * @argc: number of arguments
 * @argv: list of arguments
 *
 * Return: returns EXIT_SUCCESS on success else EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	instruction_t opcodes[] = {{"push", push_stack}, {"pall", pall},
	 {"pop", pop}, {"pint", pint}, {"swap", swap}, {"add", add}
	};
	stack_t *stack = NULL;
	int line_number = 1, getline_res = 0;
	size_t buf_size = 0;

	if (argc != 2)
	{

		error_message("USAGE: monty file", "", &stack);
	}
	the_global.file = fopen(argv[1], "r");
	if (!the_global.file)
		error_message("Error: Can't open file ", argv[1], &stack);
	while (1)
	{
		getline_res = getline(&the_global.Line_buffer, &buf_size, the_global.file);
		if (getline_res == EOF)
			break;
		check_opc(strtok(the_global.Line_buffer, " \t"), &opcodes, line_number,
			&stack);
		line_number++;
	}
	free_all(&stack);
	return (EXIT_SUCCESS);

}
/**
* check_opc - Checks if the opcode is valid and executes it.
* @Line_buffer: Opcode given by the user (after strtok).
* @opcodes: Valid opcodes.
* @line_number: Line number of script.
* @stack: Stack (or queue) to work with.
*/
void check_opc(char *Line_buffer, instruction_t (*opcodes)[], int line_number,
stack_t **stack)
{
	int i, len = strlen(Line_buffer);
	char message[100];

	if (Line_buffer[len - 1] == '\n')
		Line_buffer[len - 1] = 0;
	if (!strcmp(Line_buffer, "nop") || Line_buffer[0] == '#')
		return;
	if (!strcmp(Line_buffer, ""))
		return;
	if (!strcmp(Line_buffer, "queue"))
	{
		(*opcodes)[0].f = push_queues;
		return;
	}
	if (!strcmp(Line_buffer, "stack"))
	{
		(*opcodes)[0].f = push_stack;
		return;
	}
	for (i = 0; i < 14; i++)
	{
		if (!strcmp(Line_buffer, (*opcodes)[i].opcode))
		{
			(*opcodes)[i].f(stack, line_number);
			return;
		}
	}
	if (i == 14)
	{
		sprintf(message, "L%d: unknown instruction %s", line_number, Line_buffer);
		error_message(message, "", stack);
	}
	return;

}

