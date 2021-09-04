#ifndef STACK_SORT_H
# define STACK_SORT_H

# include <stdbool.h>

struct s_dllnode
{
	int					num;
	struct s_dllnode	*prev;
	struct s_dllnode	*next;
};
typedef struct s_dllnode	t_dllnode;

struct s_stack
{
	t_dllnode	*top;
	int			size;
};
typedef struct s_stack		t_stack;

t_dllnode	*stack_pop(t_stack *stack);
void		pa(void);
void		sa(void);
void		stack_swaptop(t_stack	*stack);
void		pb(void);
void		stack_poppush(t_stack *src, t_stack *dst);
bool		is_stack_sorted(t_stack a);
void		stack_sort(t_stack *a, int min);
void		rra(void);
void		ra(void);
void		stack_revrotate(t_stack *stack);
void		stack_rotate(t_stack *stack);

#endif /* STACK_SORT_H */
