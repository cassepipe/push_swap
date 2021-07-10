#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack_operations.h"

t_stack *new_stack(t_dllnode *top, int size)
{
	t_stack *new_stack;

	new_stack = malloc(sizeof(t_stack*));
	if (!new_stack)
			return (NULL);
	new_stack->top = top;
	new_stack->size = size;

	return(new_stack);
}

void	*stack_append(t_stack *stack, t_dllnode* node)
{
	if (stack->top)
	{
		node->prev = stack->top->prev;
		node->next = stack->top;
		stack->top->prev->next = node;
		stack->top->prev = node;
	}
	else
	{
		node->prev = node;
		node->next = node;
		stack->top = node;
	}
	stack->size++;
	return (stack);
}

void	stack_rotate(t_stack *stack)
{
	if (stack && stack->top)
		stack->top = stack->top->next;
}

void	stack_revrotate(t_stack *stack)
{
	if (stack && stack->top)
		stack->top = stack->top->prev;
}

t_dllnode	*stack_pop(t_stack *stack)
{
	t_dllnode	*ret;

	stack->top->next->prev = stack->top->prev;
	stack->top->prev->next = stack->top->next;
	ret = stack->top;
	stack->top = stack->top->next;
	if (stack->size > 0)
		stack->size--;
	if (stack->size == 0)
		stack->top = NULL;
	return (ret);
}

void	stack_push(t_stack *stack, t_dllnode *node)
{
	stack_append(stack, node);
	if (stack->size > 1)
		stack_revrotate(stack);
}

void	stack_swaptop(t_stack *stack)
{
	t_dllnode *first;
	t_dllnode *second;
	if (stack && stack->top)
	{
		first = stack_pop(stack);
		second = stack_pop(stack);
		stack_push(stack, first);
		stack_push(stack, second);
	}
}

void	stack_poppush(t_stack *src, t_stack *dst)
{
	t_dllnode *tmp;

	if (src && src->top)
	{
		tmp = stack_pop(src);
		/*printf("Popped %d out of stack A\n", tmp->num);*/
		stack_push(dst, tmp);
	}
}

void	empty_stack(t_stack *stack)
{
	free_dll(&stack->top, stack->size);
	stack->size = 0;
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

