#ifndef DLL_NODE_H
# define DLL_NODE_H

typedef struct s_dllnode
{
	int					num;
	struct s_dllnode	*prev;
	struct s_dllnode	*next;
}	t_dllnode;

#endif /* DLL_NODE_H */
