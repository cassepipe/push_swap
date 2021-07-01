#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "new_int_array.h"
#include "stack.h"

#define PRINT_INT_ARRAY(array, size)	do {	\
	int i = 0;						\
	while (i < size)				\
	{								\
		printf("%i\t", array[i]);	\
		i++;						\
	}								\
	printf("\n");					\
} while (0);

#define PRINT_INT_ARRAY_HEX(array, size)	do {	\
	int i = 0;						\
	while (i < size)				\
	{								\
		printf("%X\t", array[i]);	\
		i++;						\
	}								\
	printf("\n");					\
} while (0);


static void	pb()
{
	write(1, "pb\n", 3);
}

static void	ra()
{
	write(1, "ra\n", 3);
}

static void	pa()
{
	write(1, "pa\n", 3);
}

static void sa()
{
	write(1, "sa\n", 3);
}

int pos_modulo(int a, int b)
{
	int m;
	m = a % b;
	if (m < 0) {
		m = (b < 0) ? m - b : m + b;
	}
	return m;
}

static void	rra(int *a, int* b, int *c, int nb_items)
{
	*a = pos_modulo((*a - 1), nb_items);
	*b = pos_modulo((*b - 1), nb_items);
	*c = pos_modulo((*b - 1), nb_items);
	write(1, "rra\n", 4);
}

static void swap_int(int *a, int *b)
{
		int tmp;
		tmp = *a;
		*a = *b;
		*b = tmp;
}

int 		*small_sort(int *array, int nb_items)
{
	int top;
	int below;
	int max;
	int min;
	int b_size;

	top = 0;
	below = 1;
	max = nb_items - 1;
	min = 0;
	b_size = 0;

	if (array[top] == min)
	{
			pb();
			min++;
			b_size++;
			array[top] = -1;
	}
	else if (array[top] > array[below])
	{
			sa();
			swap_int(&array[top], &array[below]);
	}
	rra(&top, &below, nb_items);






	return (array);
}
