/* This file was automatically generated.  Do not edit! */
#undef INTERFACE
typedef struct s_stack s_stack;
typedef struct s_dllnode s_dllnode;
struct s_dllnode {
	int				num;
	struct s_dllnode	*prev;
	struct s_dllnode	*next;
};
typedef struct s_dllnode t_dllnode;
struct s_stack {
	t_dllnode *top;
	int size;
};
typedef struct s_stack t_stack;
bool is_stack_sorted(t_stack A);
void print_two_stacks(t_stack A,t_stack B);
void print_stack(t_stack stack);
void free_stack(t_stack *stack);
void free_dll(t_dllnode **list,int nmemb);
void empty_stack(t_stack *stack);
void stack_poppush(t_stack *src,t_stack *dst);
void stack_swaptop(t_stack *stack);
void stack_push(t_stack *stack,t_dllnode *node);
t_dllnode *stack_pop(t_stack *stack);
void stack_revrotate(t_stack *stack);
void stack_rotate(t_stack *stack);
t_stack *stack_append(t_stack *stack,t_dllnode *node);
t_stack *new_stack(t_dllnode *top,int size);
