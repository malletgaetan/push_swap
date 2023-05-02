/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmallet <gmallet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:25:26 by gmallet           #+#    #+#             */
/*   Updated: 2023/05/02 13:25:27 by gmallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	sa;
	t_stack	sb;
	t_list	*buf;
	int		err;

	if (init_list(&buf, (t_uint)argc - 1))
		return (error_handler());
	if (fill_and_validate(argv + 1, (t_uint)argc - 1, buf))
	{
		free(buf);
		return (error_handler());
	}
	init_stack(&sa, 'a', buf, (t_uint)argc - 1);
	init_stack(&sb, 'b', NULL, 0);
	err = quicksort_a(&sa, &sb, sa.len, sb.len);
	if (err)
		error_handler();
	free(buf);
	return (err);
}
