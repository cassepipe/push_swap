/* This file was automatically generated.  Do not edit! */
#undef INTERFACE
int *bit_sort_raw(int *input_array,int nb_items,int nb_bits_to_sort);
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
void empty_stack(t_stack *stack);
void stack_sort(t_stack *A);
t_dllnode *dll_new_node(int n);
void *stack_append(t_stack *stack,t_dllnode *node);
typedef struct array_member array_member;
struct array_member *radix_sort_int(struct array_member *array,int nb_items);
void check_for_duplicates(struct array_member *array,int nb_items);
struct array_member {
	int	num;
	int	offset;
	int	ord;
};
void put_array_ordered(struct array_member *int_array,int size);
void put_dll_ordered(t_dllnode **list);
void print_stack(t_stack stack);
