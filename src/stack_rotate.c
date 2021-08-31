#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack_rotate.h"

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
