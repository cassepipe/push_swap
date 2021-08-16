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
void free_stack(t_stack *stack);
void loop_exec_stack_ops(t_stack *A,t_stack *B);
#include <stdio.h>
#define RED "\033[31m"
#define ENDCOLOR "\033[0m"
#define GREEN "\033[92m"
bool is_stack_sorted(t_stack A);
void put_stack_ordered(t_stack stack);
t_dllnode *dll_new_node(int n);
t_stack *stack_append(t_stack *stack,t_dllnode *node);
int atoi_error(const char *ptr,bool *error);
t_stack *new_empty_stack(void);
