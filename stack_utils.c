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

void	empty_stack(t_stack *stack)
{
	if (stack)
	{
		free_dll(&stack->top, stack->size);
		stack->size = 0;
	}
}

void	free_stack(t_stack *stack)
{
	free_dll(&stack->top, stack->size);
	free(stack);
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

void	print_two_stacks(t_stack A, t_stack B)
{
	printf("\x1b[2J");
	if (A.size > B.size)
		while (A.size > B.size)
		{
			printf("\t%i", A.top->num);
			printf("\n");
			A.top = A.top->next;
			A.size--;
		}
	else
		while (B.size > A.size)
		{
			printf("\t\t%i", B.top->num);
			printf("\n");
			B.top = B.top->next;
			B.size--;
		}
	while (A.size-- && B.size--)
	{
		printf("\t%i", A.top->num);
		printf("\t\t%i", B.top->num);
		printf("\n");
		A.top = A.top->next;
		B.top = B.top->next;
	}
}

bool	is_stack_sorted(t_stack A)
{
	while (--A.size)
	{
		if (A.top->num > A.top->next->num)
			return (false);
		stack_rotate(&A);
	}
	return (true);
}
