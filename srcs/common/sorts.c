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

t_uint	sort_inst_part(t_stack *s, t_uint len, int instructions[5], t_bool (*cmp)(int, int))
{
	int	arr[3];
	t_uint	i;

	// printf("sort_inst_part on s%c with len %u\n", s->id, len);
	if (is_stack_sorted(s, len, cmp))
		return (0);
	cpy(s, len, arr);
	i = 0;
	if (len == 2)
	{
		instructions[0] = SWAP;
		return (1);
	}
	if ((len == 3) && (!cmp(arr[0], arr[2]) || !cmp(arr[1], arr[2])))
	{
		if (!cmp(arr[0], arr[1]) && !cmp(arr[0], arr[2]))
		{
			instructions[i++] = SWAP;
			swap_values(&(arr[0]), &(arr[1]));
		}
		instructions[i++] = ROTATE;
		instructions[i++] = SWAP;
		swap_values(&(arr[1]), &(arr[2]));
		instructions[i++] = RROTATE;
	}
	if (!cmp(arr[0], arr[1]))
		instructions[i++] = SWAP;
	return (i);
}

t_uint	sort_inst_entire(t_stack *s, t_uint len, int instructions[5], t_bool (*cmp)(int, int))
{
	int	arr[3];
	int	last;
	t_uint	i;
	t_uint	a;
	t_uint	b;

	// printf("sort_inst_entire on s%c with len %u\n", s->id, len);
	if (is_stack_sorted(s, len, cmp))
		return (0);
	if (len == 2)
	{
		instructions[0] = SWAP;
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
	i = 0;
	a = 0;
	b = 1;
	if (arr[0] == last)
	{
		++a;
		++b;
		instructions[i++] = ROTATE;
	}
	else if (arr[1] == last)
	{
		a = 2;
		--b;
		instructions[i++] = RROTATE;
	}
	if (!cmp(arr[a], arr[b]))
		instructions[i++] = SWAP;
	return (i);
}
