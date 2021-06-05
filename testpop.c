
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "dll.h"
#include "libft/get_next_line.h"

#define ENDCOLOR "\033[0m"
#define GREEN "\033[92m"
#define RED "\033[31m"

bool	check_ordered(t_dllnode **numbers);
void	print_both_dll(t_dllnode **a, int size_a, t_dllnode **b, int size_b);
void	print_dll(t_dllnode **a, int size_a);
void	free_dll(t_dllnode **list, int nmemb);

struct s_fat_token {
	char *token;
	void (*operation)(t_dllnode **list);
};

void	put_ordered(t_dllnode **list)
{
	if (check_ordered(list))
		printf(GREEN "OK" ENDCOLOR "\n");
	else
		printf(RED "KO" ENDCOLOR "\n");
}

int 	main(int argc, char **argv)
{
	int i;
	int y;
	int max;
	t_dllnode **a;
	t_dllnode **b;
	char *line;

	argv++;
	argc--;
	a = malloc(sizeof(t_dllnode**));
	b = malloc(sizeof(t_dllnode**));
	if (!a || !b)
		return (0);
	*a = NULL;
	*b = NULL;
	y = 0;
	i = 0;
	while (i < argc)
	{
		a = dll_append(a, dll_new_node(atoi(argv[i])));
		i++;
	}
	max = i;

	print_both_dll(a, i, b, y);

	while (get_next_line(STDOUT_FILENO, &line))
	{
		if (line[0] == 's')
		{
			if (line[1] == 'a')
			{
				dll_swaptop(a);
				/*i--;*/
			}
			else if (line[1] == 'b')
				dll_swaptop(b);
		}
		if (line[0] == 'p')
		{
			if (line[1] == 'a')
			{
				dll_poppush(b,a);
				i++;
				y--;
			}
			else if (line[1] == 'b')
			{
				dll_poppush(a,b);
				y++;
				i--;
			}
		}
		if (line[0] == 'r')
		{
			if (line[1] == 'r')
			{
				if (line[2] == 'a')
					dll_revrotate(a);
				else if (line[2] == 'b')
					dll_revrotate(b);
				else if (line[2] == 'r')
				{
					dll_revrotate(a);
					dll_revrotate(b);
				}
				else
				{
					dll_rotate(a);
					dll_rotate(b);
				}
			}
			else if (line[1] == 'a')
				dll_rotate(a);
			else if (line[1] == 'b')
				dll_rotate(b);
		}
		i = i < max ? i : max;
		y = y < max ? y : max;
		free(line);
		/*print_both_dll(a, i, b, y);*/
		print_dll(a, i);
		printf("\n---------------------------------------------\n");
		print_dll(b, y);
		put_ordered(a);
	}
	free(line);

	free_dll(a, i);
	free_dll(b, y);
	free(a);
	free(b);

	return (0);
}


void	print_both_dll(t_dllnode **a, int size_a, t_dllnode **b, int size_b)
{
	size_a = size_a > 0 ? size_a : 0;
	size_b = size_b > 0 ? size_b : 0;
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
	put_ordered(a);
}

bool	check_ordered(t_dllnode **list)
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
