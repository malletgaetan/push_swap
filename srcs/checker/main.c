/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmallet <gmallet@student.42lehavre.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:25:19 by gmallet           #+#    #+#             */
/*   Updated: 2023/06/14 12:46:03 by gmallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	ft_islower(char c)
{
	return ((c >= 'a') && (c <= 'z'));
}

int	is_instruction(char *buf, char *inst)
{
	size_t	i;

	i = 0;
	while (ft_islower(buf[i]) && (*inst))
	{
		if (buf[i] != *(inst++))
			return (0);
		++i;
	}
	return (!(*inst) && buf[i] == '\n');
}

int	execute_instruction(t_stack *sa, t_stack *sb, char *buf)
{
	if (is_instruction(buf, "pa"))
		return (push(sb, sa));
	if (is_instruction(buf, "pb"))
		return (push(sa, sb));
	if (is_instruction(buf, "sa"))
		return (swap(sa));
	if (is_instruction(buf, "sb"))
		return (swap(sb));
	if (is_instruction(buf, "ss"))
		return (swap_both(sa, sb));
	if (is_instruction(buf, "ra"))
		return (rotate(sa, FALSE));
	if (is_instruction(buf, "rb"))
		return (rotate(sb, FALSE));
	if (is_instruction(buf, "rr"))
		return (rotate_both(sa, sb, FALSE));
	if (is_instruction(buf, "rra"))
		return (rotate(sa, TRUE));
	if (is_instruction(buf, "rrb"))
		return (rotate(sb, TRUE));
	if (is_instruction(buf, "rrr"))
		return (rotate_both(sa, sb, TRUE));
	return (1);
}

int	interpret_instructions(t_stack *sa, t_stack *sb)
{
	char	*instruction;

	instruction = get_next_line(STDIN_FILENO);
	while (instruction)
	{
		if (execute_instruction(sa, sb, instruction))
			return (1);
		instruction = get_next_line(STDIN_FILENO);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	sa;
	t_stack	sb;
	t_list	*buf;

	if (init_list(&buf, (t_uint)argc - 1))
		return (error_handler());
	if (fill_and_validate(argv + 1, (t_uint)argc - 1, buf))
	{
		free(buf);
		return (error_handler());
	}
	init_stack(&sa, 'a', buf, (t_uint)argc - 1);
	init_stack(&sb, 'b', NULL, 0);
	if (interpret_instructions(&sa, &sb))
	{
		free(buf);
		return (error_handler());
	}
	if (is_stack_sorted(&sa, (t_uint)argc - 1, asc_cmp))
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	free(buf);
	return (0);
}
