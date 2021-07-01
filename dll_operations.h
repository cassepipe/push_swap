/* This file was automatically generated.  Do not edit! */
#undef INTERFACE
typedef struct s_dllnode s_dllnode;
struct s_dllnode {
	int				num;
	struct s_dllnode	*prev;
	struct s_dllnode	*next;
};
typedef struct s_dllnode t_dllnode;
void print_dll(t_dllnode **a,int size_a);
void free_dll(t_dllnode **list,int nmemb);
void dll_poppush(t_dllnode **a,t_dllnode **b);
void dll_swaptop(t_dllnode **head);
void dll_push(t_dllnode **dll,t_dllnode *node);
t_dllnode *dll_pop(t_dllnode **head);
void dll_revrotate(t_dllnode **head);
void dll_rotate(t_dllnode **head);
t_dllnode **dll_append(t_dllnode **head,t_dllnode *node);
t_dllnode *dll_new_node(int n);
