
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "dll.h"

#define ENDCOLOR "\033[0m"
#define GREEN "\033[92m"
#define RED "\033[31m"

bool	check_ordered(int *numbers, int size);
void	print_both_dll(t_stack **a, int size_a, t_stack **b, int size_b);
void	print_dll(t_stack **a, int size_a);
void	free_dll(t_stack **list, int nmemb);

int 	main(int argc, char **argv)
{
	int	numbers[argc - 1];
	int i;
	int op_n;
	t_stack **a;
	t_stack **b;

	argv++;
	argc--;
	b = NULL;
	i = 0;
	while (i < argc)
	{
		dll_append(a, dll_new_node(atoi(argv[i])));
		i++;
	}
	i++;

	print_dll(a, i);
	/*print_both_dll(a, i, a, i - 2);*/
	/*print_both_dll(a, i, b, 0);*/
	if (check_ordered(numbers, argc))
		printf(GREEN "OK" ENDCOLOR "\n");
	else
		printf(RED "KO" ENDCOLOR "\n");

	free_dll(a, i);
	/*free_dll(b, 0);*/

	op_n = 0;

	return (0);
}

void	free_dll(t_stack **list, int nmemb)
{
	t_stack *node;

	if (list)
	{
		if (*list)
		{
			node = (*list)->next;
			while (--nmemb)
			{
				node = node->next;
				free(node->prev);
			}
			free(*list);
		}
	}
}

void	print_dll(t_stack **a, int size_a)
{
	size_a = size_a > 0 ? size_a: 0;

	while (size_a--)
	{
		printf("\t%i", (*a)->num);
		puts("\n");
		*a = (*a)->next;
	}
}

void	print_both_dll(t_stack **a, int size_a, t_stack **b, int size_b)
{
	size_a = size_a > 0 ? size_a : 0;
	size_a = size_a > 0 ? size_b : 0;
	if (size_a > size_b)
		while (size_a > size_b)
		{
			printf("\t%i", (*a)->num);
			printf("\n");
			*a = (*a)->next;
			size_a--;
		}
	else
		while (size_b > size_a)
		{
			printf("\t\t%i", (*b)->num);
			printf("\n");
			*b = (*b)->next;
			size_b--;
		}
	while (size_a-- && size_b--)
	{
		printf("\t%i", (*a)->num);
		printf("\t\t%i", (*b)->num);
		puts("\n");
		*a = (*a)->next;
		*b = (*b)->next;
	}
}

bool	check_ordered(int *numbers, int size)
{
	int *next_num;
	int *end;

	next_num = numbers + 1;
	end = numbers + size;
	while (next_num != end)
	{
		if (*numbers > *next_num)
			break;
		numbers++;
		next_num++;
	}
	if (next_num == end)
		return (true);
	else
		return (false);
}
