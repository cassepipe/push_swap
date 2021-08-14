#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <libft/get_next_line.h>
#include <fcntl.h>
#include "checker.h"

bool	check_dll_ordered(t_dllnode **list)
{
	t_dllnode	*node;
	t_dllnode	*next_node;

	if (list && *list)
	{
		node = (*list);
		next_node = (*list)->next;
		while (next_node != *list)
		{
			if (node->num > next_node-> num)
				return (false);
			node = next_node;
			next_node = next_node->next;
		}
	}
	return (true);
}

void	put_dll_ordered(t_dllnode **list)
{
	if (check_dll_ordered(list))
		printf(GREEN "OK" ENDCOLOR "\n");
	else
		printf(RED "KO" ENDCOLOR "\n");
}

void	loop_exec_stack_ops(t_stack *A, t_stack *B)
{
	size_t		size;
	char	*line;

	size = 512;
	line = malloc(512);

	while (get_next_line(STDINp&line) != -1)
	{
		if (line[0] == 's')
		{
			if (line[1] == 'a')
				stack_swaptop(A);
			else if (line[1] == 'b')
				stack_swaptop(B);
			else if (line[1] == 's')
			{
				stack_swaptop(A);
				stack_swaptop(B);
			}
		}
		if (line[0] == 'p')
		{
			if (line[1] == 'a')
				stack_poppush(B, A);
			else if (line[1] == 'b')
				stack_poppush(A, B);
		}
		if (line[0] == 'r')
		{
			if (line[1] == 'r')
			{
				if (line[2] == 'A')
					stack_revrotate(A);
				else if (line[2] == 'b')
					stack_revrotate(B);
				else if (line[2] == 'r')
				{
					stack_revrotate(A);
					stack_revrotate(B);
				}
				else
				{
					stack_rotate(A);
					stack_rotate(B);
				}
			}
			else if (line[1] == 'a')
				stack_rotate(A);
			else if (line[1] == 'b')
				stack_rotate(B);
		}
		free(line);
		PRINT_TWO_STACKS(A, B);
	}
	free(line);
}

int 	main(int argc, char **argv)
{
	t_stack	*A;
	t_stack	*B;
	int		i;
	int		num;

	argv++;
	argc--;
	A = new_stack(NULL, 0);
	B = new_stack(NULL, 0);
	if (!A || !B)
		return (-1);
	i = 0;
	while (i < argc)
	{
		/*printf("Appending %c\n", **argv);*/
		num = atoi(*argv++);
		i++;
		stack_append(A, dll_new_node(num));
	}
	PRINT_TWO_STACKS(A, B);
	loop_exec_stack_ops(A, B);
	PRINT_TWO_STACKS(A, B);
	free_stack(A);
	free_stack(B);
	return (0);
}
