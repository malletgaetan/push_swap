#include "push_swap.h"

int	init_list(t_list **lst, t_uint len)
{
	*lst = malloc(len * sizeof(t_list));
	if (!*lst)
		return (1);
	return (0);
}

t_list	*ft_lstnew(int value)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->value = value;
	ptr->next = NULL;
	ptr->previous = NULL;
	return (ptr);
}

