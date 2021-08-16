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
#include <stdio.h>
void print_stack(t_stack stack);
#define PRINT_TWO_STACKS(A, B) do { \
	/*printf("\x1b[2J");*/	\
	/*printf("\x1b[H");*/	\
	printf("\n\tSTACK A\n--------------------------\n");	\
	print_stack(*A);					\
	printf("\n\tSTACK B\n--------------------------\n");   	\
	print_stack(*B);					\
} while (0);
t_dllnode *dll_new_node(int n);
t_stack *stack_append(t_stack *stack,t_dllnode *node);
t_stack *new_stack(t_dllnode *top,int size);
void stack_rotate(t_stack *stack);
void stack_revrotate(t_stack *stack);
void stack_poppush(t_stack *src,t_stack *dst);
void stack_swaptop(t_stack *stack);
void loop_exec_stack_ops(t_stack *A,t_stack *B);
#define RED "\033[31m"
#define ENDCOLOR "\033[0m"
#define GREEN "\033[92m"
void put_dll_ordered(t_dllnode **list);
bool check_dll_ordered(t_dllnode **list);
