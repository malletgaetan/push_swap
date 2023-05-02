/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmallet <gmallet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:24:23 by gmallet           #+#    #+#             */
/*   Updated: 2023/05/02 13:39:38 by gmallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*stack_pop(t_stack *s)
{
	t_list	*ptr;

	ptr = s->top;
	if (!(s->top))
		return (ptr);
	if (s->top->next == s->top)
	{
		s->top = NULL;
	}
	else
	{
		s->top->next->previous = s->top->previous;
		s->top->previous->next = s->top->next;
		s->top = s->top->next;
	}
	return (ptr);
}

int	stack_push(t_stack *from, t_stack *to)
{
	t_list	*ptr;

	ptr = stack_pop(from);
	if (!ptr)
		return (1);
	--(from->len);
	++(to->len);
	if (!(to->top))
	{
		to->top = ptr;
		to->top->next = to->top;
		to->top->previous = to->top;
		return (0);
	}
	ptr->next = to->top;
	ptr->previous = to->top->previous;
	to->top->previous = ptr;
	ptr->previous->next = ptr;
	to->top = ptr;
	return (0);
}

void	stack_swap(t_stack *stack)
{
	if (stack->len == 1)
		return ;
	swap_values(&(stack->top->value), &(stack->top->next->value));
}

void	stack_rotate(t_stack *stack, t_bool reverse)
{
	if (!stack->top)
		return ;
	if (reverse)
		stack->top = stack->top->previous;
	else
		stack->top = stack->top->next;
}

int	stack_value(t_stack *stack, t_uint index)
{
	t_uint	i;
	t_list	*lst;

	i = 0;
	lst = stack->top;
	while (i < index)
	{
		lst = lst->next;
		++i;
	}
	return (lst->value);
}
