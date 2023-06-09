/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmallet <gmallet@student.42lehavre.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:47:07 by gmallet           #+#    #+#             */
/*   Updated: 2023/06/13 20:57:55 by gmallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INVALID_NUMBERS 4
# define TRUE 1
# define FALSE 0
# define ERROR_MSG "Error\n"
# define ERROR_MSG_LEN 6
# define END 0
# define SWAP 1
# define SWAP_A 2
# define SWAP_B 3
# define ROTATE 4
# define ROTATE_A 5
# define ROTATE_B 6
# define RROTATE 7
# define RROTATE_A 8
# define RROTATE_B 9
# ifdef CHECKER
#  define PRINT_INSTRUCTIONS 0
# else
#  define PRINT_INSTRUCTIONS 1
# endif

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef unsigned char	t_bool;

typedef unsigned int	t_uint;

typedef struct s_list
{
	int				value;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;

typedef struct s_stack
{
	t_list	*top;
	t_uint	len;
	t_uint	first;
	char	id;
}	t_stack;

typedef struct s_inst
{
	int		arr[5];
	t_uint	len;
}	t_inst;

void	init_stack(t_stack *stack, char id, t_list *top, t_uint len);
int		stack_push(t_stack *from, t_stack *to);
void	stack_swap(t_stack *stack);
void	stack_rotate(t_stack *stack, t_bool reverse);
int		stack_value(t_stack *stack, t_uint index);

t_bool	desc_cmp(int a, int b);
t_bool	asc_cmp(int a, int b);
t_bool	is_stack_sorted(t_stack *stack, t_uint len, t_bool (*cmp)(int, int));

int		fill_and_validate(char **numbers, t_uint len, t_list *lst);

int		get_median(t_stack *stack, t_uint len, int *res);

void	sort_and_merge(t_stack *sa, t_stack *sb, t_uint len_a, t_uint len_b);

int		push(t_stack *from, t_stack *to);
int		rotate_both(t_stack *sa, t_stack *sb, t_bool reverse);
int		rotate(t_stack *stack, t_bool reverse);
int		swap(t_stack *stack);
int		swap_both(t_stack *sa, t_stack *sb);

int		quicksort_a(t_stack *sa, t_stack *sb, t_uint len_a, t_uint len_b);

int		init_list(t_list **lst, t_uint len);
t_list	*ft_lstnew(int value);

void	swap_values(int *a, int *b);
int		error_handler(void);

t_uint	sort_part(t_stack *s, t_uint len, t_inst *ist, t_bool (*cmp)(int, int));
t_uint	sort_all(t_stack *s, t_uint len, t_inst *inst, t_bool (*cmp)(int, int));
void	merge_instructions(t_inst *i_a, t_inst *i_b, int res[10]);

#endif
