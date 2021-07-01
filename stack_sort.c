#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "new_int_array.h"
#include "stack.h"

static void	pb()
{
	write(1, "pb\n", 3);
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

void 	stack_sort(t_stack *A)
{
	t_stack B;
	int min;

	B = (t_stack){ .top = NULL, .size = 0};
	min = 0;

	while (!is_stack_sorted(*A) && min < A->size)
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
			stack_revrotate(A);
			rra();
		}
	}
	while (B.size--)
	{
		free(stack_pop(&B));
		pa();
	}
}
