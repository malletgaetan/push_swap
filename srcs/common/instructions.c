/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmallet <gmallet@student.42lehavre.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:23:52 by gmallet           #+#    #+#             */
/*   Updated: 2023/06/13 20:51:52 by gmallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack *from, t_stack *to)
{
	char	msg[3];

	msg[0] = 'p';
	msg[1] = to->id;
	msg[2] = '\n';
	if (stack_push(from, to))
		return (0);
	if (PRINT_INSTRUCTIONS)
		write(STDOUT_FILENO, msg, 3);
	return (0);
}

int	rotate_both(t_stack *sa, t_stack *sb, t_bool reverse)
{
	char	msg[4];

	msg[0] = 'r';
	msg[1] = 'r';
	msg[2] = 'r';
	msg[3] = '\n';
	stack_rotate(sa, reverse);
	stack_rotate(sb, reverse);
	if (PRINT_INSTRUCTIONS)
		write(STDOUT_FILENO, msg + !reverse, 3 + reverse);
	return (0);
}

int	rotate(t_stack *stack, t_bool reverse)
{
	char	msg[4];

	msg[0] = 'r';
	msg[1] = 'r';
	msg[2] = stack->id;
	msg[3] = '\n';
	stack_rotate(stack, reverse);
	if (PRINT_INSTRUCTIONS)
		write(STDOUT_FILENO, msg + !reverse, 3 + reverse);
	return (0);
}

int	swap(t_stack *stack)
{
	char	msg[3];

	msg[0] = 's';
	msg[1] = stack->id;
	msg[2] = '\n';
	stack_swap(stack);
	if (PRINT_INSTRUCTIONS)
		write(STDOUT_FILENO, msg, 3);
	return (0);
}

int	swap_both(t_stack *sa, t_stack *sb)
{
	stack_swap(sa);
	stack_swap(sb);
	if (PRINT_INSTRUCTIONS)
		write(STDOUT_FILENO, "ss\n", 3);
	return (0);
}
