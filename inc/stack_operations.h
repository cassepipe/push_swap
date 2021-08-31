#ifndef STACK_OPERATIONS_H
# define STACK_OPERATIONS_H

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

void		stack_poppush(t_stack *src, t_stack *dst);
void		stack_swaptop(t_stack *stack);
void		stack_revrotate(t_stack *stack);
void		stack_push(t_stack *stack, t_dllnode *node);
t_dllnode	*stack_pop(t_stack *stack);
t_stack		*stack_append(t_stack *stack, t_dllnode *node);

#endif /* STACK_OPERATIONS_H */
