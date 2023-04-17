#include "push_swap.h"

void	merge_instructions(int i_a[5], int i_b[5], t_uint a_len, t_uint b_len, int res[10])
{
	t_uint	i;
	t_uint	j;
	t_uint	k;

	i = 0;
	j = 0;
	k = 0;
	while ((i < a_len) && (j < b_len))
	{
		if (i_a[i] == i_b[j])
		{
			res[k++] = i_a[i++];
			++j;
		}
		else if ((a_len - i) > (b_len - j))
			res[k++] = i_a[i++] + 1;
		else
			res[k++] = i_b[j++] + 2;
	}
	while (i < a_len)
		res[k++] = i_a[i++] + 1;
	while (j < b_len)
		res[k++] = i_b[j++] + 2;
	if (k < 10)
		res[k] = END;
}