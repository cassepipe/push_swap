#ifndef DLL_OPERATIONS_H
# define DLL_OPERATIONS_H

struct	s_dllnode
{
	int					num;
	struct s_dllnode	*prev;
	struct s_dllnode	*next;
};
typedef struct s_dllnode	t_dllnode;

void		free_dll(t_dllnode **list, int nmemb);
t_dllnode	*dll_new_node(int n);

#endif /* DLL_OPERATIONS_H */
