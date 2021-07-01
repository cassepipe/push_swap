#ifndef STACK_H
# define STACK_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "dll.h"

typedef struct	s_stack	{
	t_dllnode *top;
	int size;
} t_stack;

t_stack 	*new_stack(t_dllnode *top, int size);
t_stack		*stack_append(t_stack *stack, t_dllnode *node);
void		stack_rotate(t_stack *stack);
void		stack_revrotate(t_stack *stack);
t_dllnode	*stack_pop(t_stack *stack);
void		stack_push(t_stack *stack, t_dllnode *node);
void		stack_swaptop(t_stack *stack);
void		stack_poppush(t_stack *src, t_stack *dst);
void		free_stack(t_stack *stack);
void		empty_stack(t_stack *stack);
void		print_stack(t_stack stack);
void		print_two_stacks(t_stack s1, t_stack s2);
bool		is_stack_sorted(t_stack stack);

#endif
