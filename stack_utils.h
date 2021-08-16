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
void stack_rotate(t_stack *stack);
bool is_stack_sorted(t_stack A);
void free_dll(t_dllnode **list,int nmemb);
void free_stack(t_stack *stack);
t_stack *new_empty_stack(void);
t_stack *new_stack(t_dllnode *top,int size);
