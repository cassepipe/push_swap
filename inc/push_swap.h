#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>

struct	s_dllnode
{
	int					num;
	struct s_dllnode	*prev;
	struct s_dllnode	*next;
};
typedef struct s_dllnode	t_dllnode;

struct	s_stack
{
	t_dllnode	*top;
	int			size;
};
typedef struct s_stack		t_stack;

struct	s_fat_int
{
	int	num;
	int	offset;
	int	ord;
};
typedef struct s_fat_int	t_fat_int;

int			*bit_sort_raw(int *input_array, int nb_items, int max);
void		stack_sort(t_stack	*A,	int	min);
bool		check_for_some_order(int	*array,	int	nb_items,	int	min);
void		error_if_duplicates_in_fat_array(struct	s_fat_int	*array,	int	nb_items);
void		free_stack(t_stack	*stack);
t_fat_int	*fat_int_radix_sort(struct	s_fat_int	*array,	int	nb_items);
t_dllnode	*dll_new_node(int	n);
t_stack		*stack_append(t_stack	*stack,	t_dllnode	*node);
t_stack		*new_stack(t_dllnode	*top,	int	size);
t_stack		*create_stack_from_int_array(int	*int_array,	int	nb_items);
int			*create_positive_array(t_fat_int	*fat_array,	int	nb_items);
int			atoi_error(const	char	*ptr,	bool	*error);

#endif	/*	PUSH_SWAP_H	*/
