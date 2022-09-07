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
		(*opcodes)[0].f = push_q;
		return;
	}
	if (!strcmp(Line_buffer, "stack"))
	{
		(*opcodes)[0].f = push_s;
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
		error_mes(message, "", stack);
	}
	return;

}