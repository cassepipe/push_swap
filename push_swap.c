#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "dll.h"
#include "stack.h"
#include "libft/get_next_line.h"

#define ENDCOLOR "\033[0m"
#define GREEN "\033[92m"
#define RED "\033[31m"

#define PRINT_TWO_STACKS(A, B) do { \
		printf("\x1b[2J");										\
		printf("\x1b[H");										\
		printf("\n\tSTACK A\n--------------------------\n");	\
		print_stack(*A);										\
		printf("\n\tSTACK B\n--------------------------\n");   	\
		print_stack(*B);										\
		put_dll_ordered(&A->top);								\
	} while (0);												\

struct s_fat_token {
	char *token;
	void (*operation)(t_dllnode **list);
};

bool	check_dll_ordered(t_dllnode **list)
{
	t_dllnode *node;
	t_dllnode *next_node;

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
	char *line;

	while (get_next_line(STDOUT_FILENO, &line))
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
				stack_poppush(B,A);
			else if (line[1] == 'b')
				stack_poppush(A,B);
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
	t_stack *A;
	t_stack *B;

	argv++;
	argc--;
	A = new_stack(NULL, 0);
	B = new_stack(NULL, 0);
	if (!A || !B)
		return (-1);
	while (argc--)
	{
		/*printf("Appending %c\n", **argv);*/
		stack_append(A, dll_new_node(atoi(*argv++)));
	}

	PRINT_TWO_STACKS(A, B);

	loop_exec_stack_ops(A, B);

	free_stack(A);
	free_stack(B);

	return (0);
}

