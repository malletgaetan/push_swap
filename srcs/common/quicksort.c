/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmallet <gmallet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:24:08 by gmallet           #+#    #+#             */
/*   Updated: 2023/05/02 13:44:33 by gmallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_uint	push_half_b(t_stack *from, t_stack *to, int median, t_uint len)
{
	t_uint	pushed_under;
	t_uint	_len;
	t_uint	i;

	_len = len;
	i = 0;
	pushed_under = 0;
	while (len > (_len / 2))
	{
		++i;
		if (from->top->value > median
			|| ((_len % 2) && (median == from->top->value)))
		{
			push(from, to);
			--len;
			continue ;
		}
		rotate(from, FALSE);
		++pushed_under;
	}
	return (pushed_under);
}

static t_uint	push_half_a(t_stack *from, t_stack *to, int median, t_uint len)
{
	t_uint	pushed_under;
	t_uint	_len;
	t_uint	i;

	_len = len;
	i = 0;
	pushed_under = 0;
	while (len > ((_len / 2) + (_len % 2)))
	{
		++i;
		if (from->top->value < median
			|| ((_len % 2 == 0) && (median == from->top->value)))
		{
			push(from, to);
			--len;
			continue ;
		}
		rotate(from, FALSE);
		++pushed_under;
	}
	return (pushed_under);
}

static void	reset_placement(t_stack *stack, t_uint pushed_under)
{
	while (pushed_under--)
		rotate(stack, TRUE);
}

static int	quicksort_b(t_stack *sa, t_stack *sb, t_uint len)
{
	int		median;
	t_uint	pushed_under;
	int		err;

	if (is_stack_sorted(sb, len, desc_cmp))
	{
		while (len--)
			push(sb, sa);
		return (0);
	}
	if (get_median(sb, len, &median))
		return (1);
	pushed_under = push_half_b(sb, sa, median, len);
	if (sb->len > len)
		reset_placement(sb, pushed_under);
	err = quicksort_a(sa, sb, (len / 2) + (len % 2), len / 2);
	if ((len / 2) + (len % 2) > 3)
		err |= quicksort_b(sa, sb, (len / 2));
	return (err);
}

int	quicksort_a(t_stack *sa, t_stack *sb, t_uint len_a, t_uint len_b)
{
	int		median;
	int		err;
	t_uint	pushed_under;

	if (len_a <= 3)
	{
		sort_and_merge(sa, sb, len_a, len_b);
		return (0);
	}
	if (is_stack_sorted(sa, len_a, asc_cmp))
		return (0);
	if (get_median(sa, len_a, &median))
		return (1);
	pushed_under = push_half_a(sa, sb, median, len_a);
	if (sa->len > len_a)
		reset_placement(sa, pushed_under);
	err = quicksort_a(sa, sb, (len_a / 2) + (len_a % 2), (len_a / 2));
	if (((len_a / 2) + (len_a % 2)) > 3)
		err |= quicksort_b(sa, sb, (len_a / 2));
	return (err);
}
