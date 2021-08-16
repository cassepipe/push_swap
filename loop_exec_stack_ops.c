#include <stdlib.h>
#include <unistd.h>
#include "libft/get_next_line.h"
#include "loop_exec_stack_ops.h"

static void	handle_swap(char *line, t_stack *A, t_stack *B)
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

static void	handle_push(char *line, t_stack *A, t_stack *B)
{
			if (line[1] == 'a')
				stack_poppush(B, A);
			else if (line[1] == 'b')
				stack_poppush(A, B);
}

static void	handle_rotation(char *line, t_stack *A, t_stack *B)
{
			if (line[1] == 'r')
			{
				if (line[2] == 'a')
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

void	loop_exec_stack_ops(t_stack *A, t_stack *B)
{
	char	*line;

	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (line[0] == 's')
			handle_swap(line, A, B);
		if (line[0] == 'p')
			handle_push(line, A, B);
		if (line[0] == 'r')
			handle_rotation(line, A, B);
		free(line);
		/*PRINT_TWO_STACKS(A, B);*/
	}
	free(line);
}
