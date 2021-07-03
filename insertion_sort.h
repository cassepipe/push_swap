/* This file was automatically generated.  Do not edit! */
#undef INTERFACE
typedef struct s_dllnode s_dllnode;
struct s_dllnode {
	int				num;
	struct s_dllnode	*prev;
	struct s_dllnode	*next;
};
typedef struct s_dllnode t_dllnode;
typedef struct s_stack s_stack;
struct s_stack {
	t_dllnode *top;
	int size;
};
typedef struct s_stack t_stack;
t_dllnode *stack_pop(t_stack *stack);
void stack_poppush(t_stack *src,t_stack *dst);
bool is_stack_sorted(t_stack A);
void insertion_sort(t_stack *A);
void stack_revrotate(t_stack *stack);
void stack_rotate(t_stack *stack);
