#include "push_swap.h"

t_bool	desc_cmp(int a, int b)
{
	return (a > b);
}

t_bool	asc_cmp(int a, int b)
{
	return (a < b);
}

t_bool is_stack_sorted(t_stack *stack, t_uint len, t_bool (*cmp)(int, int))
{
	t_uint	i;
	t_list	*cur;

	i = 1;
	cur = stack->top;
	while (i < len)
	{
		if (!cmp(cur->value, cur->next->value))
			return (FALSE);
		cur = cur->next;
		++i;
	}
	return (TRUE);
}
