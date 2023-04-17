#include "push_swap.h"

int	push(t_stack *from, t_stack *to)
{
	char	msg[3];

	msg[0] = 'p';
	msg[1] = to->id;
	msg[2] = '\n';
	if (stack_push(from, to))
		return (1);
	write(STDOUT_FILENO, msg, 3);
	// print_stack(from, "from");
	// print_stack(to, "to");
	return (0);
}

void	rotate_both(t_stack *sa, t_stack *sb, t_bool reverse)
{
	char	msg[4];

	msg[0] = 'r';
	msg[1] = 'r';
	msg[2] = 'r';
	msg[3] = '\n';
	stack_rotate(sa, reverse);
	stack_rotate(sb, reverse);
	write(STDOUT_FILENO, msg + !reverse, 3 + reverse);
	// print_stack(sa, "sa");
	// print_stack(sb, "sb");
}

void	rotate(t_stack *stack, t_bool reverse)
{
	char	msg[4];

	msg[0] = 'r';
	msg[1] = 'r';
	msg[2] = stack->id;
	msg[3] = '\n';
	stack_rotate(stack, reverse);
	write(STDOUT_FILENO, msg + !reverse, 3 + reverse);
	// print_stack(stack, "stack");
}

void	swap(t_stack *stack)
{
	char	msg[3];

	msg[0] = 's';
	msg[1] = stack->id;
	msg[2] = '\n';
	stack_swap(stack);
	write(STDOUT_FILENO, msg, 3);
	// print_stack(stack, "stack");
}

void	swap_both(t_stack *sa, t_stack *sb)
{
	char	msg[3];

	msg[0] = 's';
	msg[1] = 's';
	msg[2] = '\n';
	stack_swap(sa);
	stack_swap(sb);
	write(STDOUT_FILENO, msg, 3);
	// print_stack(sa, "sa");
	// print_stack(sb, "sb");
}