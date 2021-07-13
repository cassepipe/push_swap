/* This file was automatically generated.  Do not edit! */
#undef INTERFACE
int *bit_sort_raw(int *input_array,int nb_items,int max);
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
void stack_sort(t_stack *A);
typedef struct fat_int fat_int;
struct fat_int *fat_int_radix_sort(struct fat_int *array,int nb_items);
void print_best_rotation(int to_rotate,int nb_items);
int *create_positive_array(struct fat_int *fat_array,int nb_items);
void free_stack(t_stack *stack);
t_dllnode *dll_new_node(int n);
t_stack *stack_append(t_stack *stack,t_dllnode *node);
t_stack *new_stack(t_dllnode *top,int size);
t_stack *create_stack_from_int_array(int *int_array,int nb_items);
int atoi_error(const char *ptr,int *error);
struct fat_int *parse_numbers(char **num_strings,int nb_items,int *parse_error);
void rra();
void ra();
void fewest_rotations(int to_rotate,int nb_items);
bool check_for_some_order(int *array,int nb_items,int min,int *to_rotate);
struct fat_int {
	int	num;
	int	offset;
	int	ord;
};
bool are_there_duplicates(struct fat_int *array,int nb_items);
