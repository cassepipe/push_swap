#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack_utils.h"

t_stack	*new_stack(t_dllnode *top, int size)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack *));
	if (!new_stack)
		return (NULL);
	new_stack->top = top;
	new_stack->size = size;
	return (new_stack);
}

t_stack	*new_empty_stack(void)
{
	return (new_stack(NULL, 0));
}

/*void	empty_stack(t_stack *stack)*/
/*{*/
/*    if (stack)*/
/*    {*/
/*        free_dll(&stack->top, stack->size);*/
/*        stack->size = 0;*/
/*    }*/
/*}*/

void	free_stack(t_stack *stack)
{
	free_dll(&stack->top, stack->size);
	free(stack);
}

bool	is_stack_sorted(t_stack A)
{
	if (A.size)
	{
		while (--A.size)
		{
			if (A.top)
				if (A.top->num > A.top->next->num)
					return (false);
			stack_rotate(&A);
		}
	}
	return (true);
}

void	print_stack(t_stack stack)
{
	if (stack.top && stack.size > 0)
	{
		while (stack.size--)
		{
			printf("\t%i", stack.top->num);
			printf("\n");
			stack.top = stack.top->next;
		}
	}
}
