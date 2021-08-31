#ifndef STACK_H
# define STACK_H

# include "dll_node.h"

typedef struct s_stack
{
	t_dllnode	*top;
	int			size;
}	t_stack;

#endif /* STACK_H */
