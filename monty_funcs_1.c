#include "monty.h"

void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void m_div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

/**
 * add - Adds the top two values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Return: The result is stored in the second value node
 */
void add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		optoken_err(short_stack_err(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	pop(stack, line_number);
}

/**
 * sub - Subtracts the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Return: The result is stored in the second value node.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		optoken_err(short_stack_err(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	pop(stack, line_number);
}

/**
 * m_div - Divides the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Return: The result is stored in the second value node
 */
void m_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		optoken_err(short_stack_err(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		optoken_err(div_err(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	pop(stack, line_number);
}

/**
 * mul - Multiplies the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Return: The result is stored in the second value node.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		optoken_err(short_stack_err(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	pop(stack, line_number);
}

/**
 * mod - Computes the modulus of the second value from the
 *             top of a stack_t linked list  by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Return: The result is stored in the second value node
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		optoken_err(short_stack_err(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		optoken_err(div_err(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	pop(stack, line_number);
}
