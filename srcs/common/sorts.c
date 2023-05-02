/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmallet <gmallet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:23:42 by gmallet           #+#    #+#             */
/*   Updated: 2023/05/02 14:30:47 by gmallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	cpy(t_stack *s, t_uint len, int arr[3])
{
	t_uint	i;
	t_list	*node;

	i = 0;
	node = s->top;
	while (i < len)
	{
		arr[i] = node->value;
		node = node->next;
		++i;
	}
}

/*
norminette is for cleaner code.
*/
t_uint	_smol(t_inst *inst, t_uint len)
{
	if (len == 2)
	{
		inst->arr[0] = SWAP;
		return (1);
	}
	return (0);
}

/*
sort_part sorts first len elements of the given stack if
there are others elements in it.
*/
t_uint	sort_part(t_stack *s, t_uint len, t_inst *inst, t_bool (*cmp)(int, int))
{
	int		arr[3];
	t_uint	i;

	if (is_stack_sorted(s, len, cmp))
		return (0);
	cpy(s, len, arr);
	i = 0;
	if (_smol(inst, len))
		return (1);
	if ((len == 3) && (!cmp(arr[0], arr[2]) || !cmp(arr[1], arr[2])))
	{
		if (!cmp(arr[0], arr[1]) && !cmp(arr[0], arr[2]))
		{
			inst->arr[i++] = SWAP;
			swap_values(&(arr[0]), &(arr[1]));
		}
		inst->arr[i++] = ROTATE;
		inst->arr[i++] = SWAP;
		swap_values(&(arr[1]), &(arr[2]));
		inst->arr[i++] = RROTATE;
	}
	if (!cmp(arr[0], arr[1]))
		inst->arr[i++] = SWAP;
	return (i);
}

/*
norminette fonk?
*/
t_uint	_sort_all(t_inst *inst, int arr[3], int last, t_bool (*cmp)(int, int))
{
	t_uint	i;
	t_uint	a;
	t_uint	b;

	i = 0;
	a = 0;
	b = 1;
	if (arr[0] == last)
	{
		++a;
		++b;
		inst->arr[i++] = ROTATE;
	}
	else if (arr[1] == last)
	{
		a = 2;
		--b;
		inst->arr[i++] = RROTATE;
	}
	if (!cmp(arr[a], arr[b]))
		inst->arr[i++] = SWAP;
	return (i);
}

/*
sort_all sorts first len elements of the given stack
if there are no others elements in it.
*/
t_uint	sort_all(t_stack *s, t_uint len, t_inst *inst, t_bool (*cmp)(int, int))
{
	int		arr[3];
	int		last;
	t_uint	i;

	if (is_stack_sorted(s, len, cmp))
		return (0);
	if (len == 2)
	{
		inst->arr[0] = SWAP;
		return (1);
	}
	cpy(s, len, arr);
	last = arr[0];
	i = 1;
	while (i < len)
	{
		if (!cmp(arr[i], last))
			last = arr[i];
		++i;
	}
	return (_sort_all(inst, arr, last, cmp));
}
