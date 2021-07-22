#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack_operations.h"

t_stack	*stack_append(t_stack *stack, t_dllnode *node)
{
	if (!node)
		return (NULL);
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
	t_dllnode	*first;
	t_dllnode	*second;

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
	t_dllnode	*tmp;

	if (src && src->top)
	{
		tmp = stack_pop(src);
		stack_push(dst, tmp);
	}
}
