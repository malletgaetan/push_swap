/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmallet <gmallet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:23:48 by gmallet           #+#    #+#             */
/*   Updated: 2023/05/02 13:38:02 by gmallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insertion_sort(int *arr, t_uint len)
{
	t_uint	i;
	int		j;
	int		key;

	i = 0;
	while (i < len)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
		++i;
	}
}

static void	arrayify(t_stack *stack, int *arr, t_uint len)
{
	t_uint	i;
	t_list	*lst;

	i = 0;
	lst = stack->top;
	while (i < len)
	{
		arr[i] = lst->value;
		lst = lst->next;
		++i;
	}
}

int	get_median(t_stack *stack, t_uint len, int *res)
{
	int	*arr;

	arr = malloc(len * sizeof(int));
	if (!arr)
		return (1);
	arrayify(stack, arr, len);
	insertion_sort(arr, len);
	*res = arr[(len / 2) - !(len % 2)];
	free(arr);
	return (0);
}
