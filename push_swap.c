#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "push_swap.h"
#include "debug.h"

bool are_there_duplicates(struct fat_int *array, int nb_items)
{
	int i;
	int y;

	i = 0;
	while (i < nb_items)
	{
		y = 0;
		while (y < nb_items)
		{
			if (array[i].num == array[y].num && i != y)
			{
				return (true);
			}
			y++;
		}
		i++;
	}
	return (false);
}

bool	check_for_some_order(int *array, int nb_items, int min, int *to_rotate)
{
	bool found_min;
	int i;

	i = 1;
	*to_rotate = 0;
	found_min = array[0] == min ? true : false;
	while (i < nb_items)
	{
		if (array[i] != min && array[i] < array[i-1])
			return (false);
		if (!found_min)
		{
			(*to_rotate)++;
			if (array[i] == min)
				found_min = true;
		}
		i++;
	}
	return (true);
}

void	fewest_rotations(int to_rotate, int nb_items)
{
		if ((float)to_rotate <= (float)nb_items / 2.0)
			while (to_rotate--)
				ra();
		else
		{
			to_rotate -= nb_items;
			while (to_rotate++)
				rra();
		}
}

int 	main(int argc, char **argv)
{
	int	i;
	int	num;
	int	max;
	struct fat_int	*array;
	int	*int_array;
	int	to_rotate;
	t_stack	A;
	bool	error;

	argv++;
	argc--;

	array = malloc(argc * sizeof(struct fat_int));
	if (!array)
		return (-1);
	i = 0;
	while (i < argc && !error)
	{
		num = atoi_error(*argv++, &error);
		array[i].num = num;
		array[i].offset = i;
		i++;
	}
	if (are_there_duplicates(array, argc) || error)
	{
			free(array);
			write(STDERR_FILENO, "Error\n", sizeof("Error\n"));
			return (-1);
	}

	array = radix_sort_int(array, argc);

	int_array = malloc(argc * sizeof(int));
	i = 0;
	while (i < argc)
	{
		int_array[array[i].offset] = i;
		i++;
	}
	free(array);
	if (check_for_some_order(int_array, argc, 0, &to_rotate))
	{
		if ((float)to_rotate <= (float)argc / 2.0)
			while (to_rotate--)
				ra();
		else
		{
			to_rotate -= argc;
			while (to_rotate++)
				rra();
		}
	}
	else if (argc < 50)
	{
		A = (t_stack){.top = NULL, .size = 0};
		i = 0;
		while(i < argc)
		{
			stack_append(&A, dll_new_node(int_array[i]));
			i++;
		}
		stack_sort(&A);
		/*selection_sort(&A);*/
		empty_stack(&A);
		/*free_dll(&A.top, A.size);*/
	}
	else
	{
		max = argc - 1;
		i = 0;
		while (max >> i)
			i++;

		int_array = bit_sort_raw(int_array, argc, i);

	}

	free(int_array);

	return (0);
}
