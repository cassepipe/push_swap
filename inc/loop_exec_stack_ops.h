#ifndef LOOP_EXEC_STACK_OPS_H
# define LOOP_EXEC_STACK_OPS_H

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

void	loop_exec_stack_ops(t_stack *A, t_stack *B);
void	stack_rotate(t_stack *stack);
void	stack_revrotate(t_stack *stack);
void	stack_poppush(t_stack *src, t_stack *dst);
void	stack_swaptop(t_stack *stack);
void	free_stack(t_stack *stack);

#endif /* LOOP_EXEC_STACK_OPS_H */
