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
	// print_stack(&sa, "sa result");
	// print_stack(&sb, "sb result");
	if (err)
		error_handler();
	else
	{
		if (is_stack_sorted(&sa, (t_uint)argc - 1, asc_cmp))
			write(STDOUT_FILENO, "OK\n", 3);
		else
			write(STDOUT_FILENO, "KO\n", 3);
	}
	free(buf);
	return (err);
}

