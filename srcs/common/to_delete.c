#include "push_swap.h"

void	print_stack(t_stack *s, char *msg)
{
	 printf("----\n%s\n", msg);
	t_uint	i;
	t_list	*cur;

	i = 0;
	cur = s->top;
	while (i < s->len)
	{
		printf("%d, ", cur->value);
		cur = cur->next;
		++i;
	}
	printf("\n----\n");
}