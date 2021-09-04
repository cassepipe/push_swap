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

static void	rotate_towards_min(t_stack *a, int min)
{
	int	r;
	int	l;

	r = stack_find(*a, min);
	l = stack_rev_find(*a, min);
	if (r < l)
	{
		ra();
		stack_rotate(a);
	}
	else
	{
		rra();
		stack_revrotate(a);
	}
}

void 	stack_sort(t_stack *a, int min)
{
	t_stack	b;

	b = (t_stack){.top = NULL, .size = 0};
	while (!is_stack_sorted(*a))
	{
		if (a->top->num == min)
		{
			stack_poppush(a, &b);
			min++;
			pb();
		}
		else if (a->top->num > a->top->next->num)
		{
			stack_swaptop(a);
			sa();
		}
		else
			rotate_towards_min(a, min);
	}
	while (b.size)
	{
		free(stack_pop(&b));
		pa();
	}
}
