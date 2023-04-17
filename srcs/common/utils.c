#include "push_swap.h"

void	swap_values(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int	error_handler(void)
{
	write(STDERR_FILENO, ERROR_MSG, ERROR_MSG_LEN);
	return (1);
}
