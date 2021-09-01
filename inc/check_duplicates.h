#ifndef CHECK_DUPLICATES_H
# define CHECK_DUPLICATES_H

# include <stdbool.h>

typedef struct s_dllnode
{
	int					num;
	struct s_dllnode	*prev;
	struct s_dllnode	*next;
}	t_dllnode;


typedef struct s_stack
{
	t_dllnode	*top;
	int			size;
}	t_stack;

struct s_fat_int
{
	int	num;
	int	offset;
	int	ord;
};


void	error_if_duplicates_in_stack(t_stack *stack);
void	free_stack(t_stack *stack);
void	error_if_duplicates(struct s_fat_int *array, int nb_items);

#endif /* CHECK_DUPLICATES_H */
