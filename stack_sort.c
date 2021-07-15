#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include "stack_sort.h"

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

void 	stack_sort(t_stack *A)
{
	t_stack	B;
	int		min;
	int		r;
	int		l;

	B = (t_stack){.top = NULL, .size = 0};
	min = 0;
	while (!is_stack_sorted(*A))
	{
		if (A->top->num == min)
		{
			stack_poppush(A, &B);
			min++;
			pb();
		}
		else if (A->top->num > A->top->next->num)
		{
			stack_swaptop(A);
			sa();
		}
		else
		{
			r = stack_find(*A, min);
			l = stack_rev_find(*A, min);
			if (r < l)
			{
				ra();
				stack_rotate(A);
			}
			else
			{
				rra();
				stack_revrotate(A);
			}
		}
	}
	while (B.size)
	{
		free(stack_pop(&B));
		pa();
	}
}
