#include "push_swap.h"

void	print_stack(t_stack *s, char *msg, t_uint len)
{
	 printf("----\n%s\n", msg);
	t_uint	i;
	t_list	*cur;
	t_uint	_len;

	i = 0;
	cur = s->top;
	if (len)
		_len = len;
	else
		_len = s->len;
	while (i < _len)
	{
		printf("%d, ", cur->value);
		cur = cur->next;
		++i;
	}
	printf("\n----\n");
}