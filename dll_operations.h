/* This file was automatically generated.  Do not edit! */
#undef INTERFACE
typedef struct s_dllnode s_dllnode;
struct s_dllnode {
	int				num;
	struct s_dllnode	*prev;
	struct s_dllnode	*next;
};
typedef struct s_dllnode t_dllnode;
void free_dll(t_dllnode **list,int nmemb);
t_dllnode *dll_new_node(int n);
