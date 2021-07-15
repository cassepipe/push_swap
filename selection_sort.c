#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include "selection_sort.h"

static int	stack_find(t_stack stack, int num)
{
	int	i;

	i = 0;
	while (stack.top->num != num)
	{
		stack_rotate(&stack);
		i++;
	}
	return (i);
}

static int	stack_rev_find(t_stack stack, int num)
{
	int	i;

	i = 0;
	while (stack.top->num != num)
	{
		stack_revrotate(&stack);
		i++;
	}
	return (i);
}

void 	selection_sort(t_stack *A)
{
	t_stack	B;
	int		min;
	int		r;
	int		l;

	B = (t_stack){ .top = NULL, .size = 0 };
	min = 0;
	while (!is_stack_sorted(*A))
	{
		r = stack_find(*A, min);
		l = stack_rev_find(*A, min);
		if (r < l)
			while (r)
			{
				ra();
				stack_rotate(A);
				r--;
			}
		else
			while (l)
			{
				rra();
				stack_revrotate(A);
				l--;
			}
		pb();
		stack_poppush(A, &B);
		min++;
	}
	while (B.size)
	{
		free(stack_pop(&B));
		pa();
	}
}
