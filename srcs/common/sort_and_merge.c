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
	int	instructions_a[5];
	int	instructions_b[5];
	int	instructions[10];
	t_uint	len_ia;
	t_uint	len_ib;

	if (sa->len == len_a)
		len_ia = sort_inst_entire(sa, len_a, instructions_a, asc_cmp);
	else
		len_ia = sort_inst_part(sa, len_a, instructions_a, asc_cmp);
	if (sb->len == len_b)
		len_ib = sort_inst_entire(sb, len_b, instructions_b, desc_cmp);
	else
		len_ib = sort_inst_part(sb, len_b, instructions_b, desc_cmp);
	merge_instructions(instructions_a, instructions_b, len_ia, len_ib, instructions);
	execute_instructions(sa, sb, instructions);
	while (len_b--)
		push(sb, sa);
}