#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include "stack_sort.h"

static void	pb()
{
	write(1, "pb\n", 3);
}

static void	ra()
{
	write(1, "ra\n", 3);
}

static void	rra()
{
	write(1, "rra\n", 4);
}

static void	pa()
{
	write(1, "pa\n", 3);
}

static void sa()
{
	write(1, "sa\n", 3);
}

static int	stack_find(t_stack stack, int num)
{
	int i;	
	
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
	int i;	
	
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
	t_stack B;
	int min;
	int r;
	int l;

	B = (t_stack){ .top = NULL, .size = 0};
	min = 0;

	while (!is_stack_sorted(*A))// && min < A->size)
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
		else //if (A->size > 2)
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
			/*stack_revrotate(A);*/
			/*rra();*/
		}
	}
	while (B.size)
	{
		free(stack_pop(&B));
		pa();
	}
}
