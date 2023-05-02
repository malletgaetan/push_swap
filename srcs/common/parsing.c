#include "push_swap.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static t_bool	ft_atoi(const char *str, int *count)
{
	int	sign;

	*count = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{

		if (*count > (INT_MAX / 10))
			return (1);
		*count = (*count * 10);
		if (*count > INT_MAX - (*str - '0'))
			return (1);
		*count += (*str - '0');
		str++;
	}
	*count *= sign;
	return (*str != '\0');
}

int fill_and_validate(char **numbers, t_uint len, t_list *lst)
{
	t_uint	i;
	t_uint	j;

	i = 0;
	while (i < len)
	{
		if (ft_atoi(numbers[i], &(lst[i].value)))
			return (1);
		if (i == 0)
		{
			++i;
			continue;
		}
		j = 0;
		while (j < i)
		{
			if (lst[j].value == lst[i].value)
				return (1);
			++j;
		}
		lst[i].previous = lst + i - 1;
		lst[i - 1].next = lst + i;
		++i;
	}
	lst[0].previous = lst + i - 1;
	lst[i - 1].next = lst;
	return (0);
}
