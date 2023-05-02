/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmallet <gmallet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:24:02 by gmallet           #+#    #+#             */
/*   Updated: 2023/05/02 14:12:06 by gmallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
merge_instructions merges 2 sorting instructions arrays into one
*/
void	merge_instructions(t_inst *a, t_inst *b, int rs[10])
{
	t_uint	i;
	t_uint	j;
	t_uint	k;

	i = 0;
	j = 0;
	k = 0;
	while ((i < a->len) && (j < b->len))
	{
		if (a->arr[i] == b->arr[j])
		{
			rs[k++] = a->arr[i++];
			++j;
		}
		else if ((a->len - i) > (b->len - j))
			rs[k++] = a->arr[i++] + 1;
		else
			rs[k++] = b->arr[j++] + 2;
	}
	while (i < a->len)
		rs[k++] = a->arr[i++] + 1;
	while (j < b->len)
		rs[k++] = b->arr[j++] + 2;
	if (k < 10)
		rs[k] = END;
}
