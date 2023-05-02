/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_and_merge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmallet <gmallet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:24:11 by gmallet           #+#    #+#             */
/*   Updated: 2023/05/02 14:15:22 by gmallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_instructions(t_stack *sa, t_stack *sb, int instructions[10])
{
	t_uint	i;

	i = 0;
	while (i < 10 && (instructions[i] != END))
	{
		if (instructions[i] == SWAP)
			swap_both(sa, sb);
		else if (instructions[i] == ROTATE)
			rotate_both(sa, sb, FALSE);
		else if (instructions[i] == RROTATE)
			rotate_both(sa, sb, TRUE);
		else if (instructions[i] == SWAP_A)
			swap(sa);
		else if (instructions[i] == SWAP_B)
			swap(sb);
		else if (instructions[i] == ROTATE_A)
			rotate(sa, FALSE);
		else if (instructions[i] == ROTATE_B)
			rotate(sb, FALSE);
		else if (instructions[i] == RROTATE_A)
			rotate(sa, TRUE);
		else
			rotate(sb, TRUE);
		++i;
	}
}

void	sort_and_merge(t_stack *sa, t_stack *sb, t_uint len_a, t_uint len_b)
{
	t_inst	inst_a;
	t_inst	inst_b;
	int		instructions[10];

	if (sa->len == len_a)
		inst_a.len = sort_all(sa, len_a, &inst_a, asc_cmp);
	else
		inst_a.len = sort_part(sa, len_a, &inst_a, asc_cmp);
	if (sb->len == len_b)
		inst_b.len = sort_all(sb, len_b, &inst_b, desc_cmp);
	else
		inst_b.len = sort_part(sb, len_b, &inst_b, desc_cmp);
	merge_instructions(&inst_a, &inst_b, instructions);
	execute_instructions(sa, sb, instructions);
	while (len_b--)
		push(sb, sa);
}
