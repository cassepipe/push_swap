#include <stdlib.h>
#include <stdio.h>
#include "dll.h"

typedef struct	s_stack	{
	t_dllnode *top;
	int size;
} t_stack;

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
		stack->top = node;
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
	return (ret);
}

void	stack_push(t_stack *stack, t_dllnode *node)
{
		stack_append(stack, node);
		stack_revrotate(stack);
}

void	stack_swaptop(t_stack *stack)
{
	t_dllnode *tmp;
	t_dllnode *second_element;
	if (stack && stack->top)
	{
		tmp = stack_pop(stack);
		/*printf("Popped struct at %lu { .prev =  %lu, .next = %lu\n", tmp, tmp->prev, tmp->next);*/
		/*printf("Popped %d out of stack A\n", tmp->num);*/
		second_element = stack->top->next;
		dll_append(&second_element, tmp);
	}
}

void	stack_poppush(t_stack *src, t_stack *dst)
{
	t_dllnode *tmp;

	if (src && src->top)
	{
		tmp = stack_pop(src);
		printf("Popped %d out of stack A\n", tmp->num);
		stack_push(dst, tmp);
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
			printf("\t%i", B.top->num);
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

