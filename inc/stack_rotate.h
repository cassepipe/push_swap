#ifndef STACK_ROTATE_H
# define STACK_ROTATE_H

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

void	stack_revrotate(t_stack *stack);
void	stack_rotate(t_stack *stack);

#endif /* STACK_ROTATE_H */
