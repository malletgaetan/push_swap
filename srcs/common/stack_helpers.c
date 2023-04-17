#include "push_swap.h"

void	init_stack(t_stack *stack, char id, t_list *top, t_uint len)
{
	stack->top = top;
	stack->len = len;
	stack->id = id;
}
