#include <stdlib.h>

typedef	struct	s_stack	{
	int				num;
	struct s_stack	*prev;
	struct s_stack	*next;
} t_stack;

t_stack	*dll_new_node(int n);
t_stack **dll_append(t_stack **head, t_stack *node);
void	dll_rotate(t_stack **head);
void	dll_revrotate(t_stack **head);
void	dll_swaptop(t_stack **head);
t_stack	*dll_pop(t_stack **head);
void	dll_push(t_stack **dll, t_stack *node);
void	dll_poppush(t_stack **a, t_stack **b);
void	free_dll(t_stack **list, int nmemb);
void	print_dll(t_stack **a, int size_a);
