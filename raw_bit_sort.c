#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "new_int_array.h"

#define PRINT_ARRAY(array, size)	do {	\
	int i = 0;						\
	while (i < size)				\
	{								\
		printf("%li\t", array[i]);	\
		i++;						\
	}								\
	printf("\n");					\
} while (0);

#define PRINT_ARRAY_HEX(array, size)	do {	\
	int i = 0;						\
	while (i < size)				\
	{								\
		printf("%X\t", array[i]);	\
		i++;						\
	}								\
	printf("\n");					\
} while (0);

#define SWAP_BUFFERS(buff1, buff2)	do {	\
	unsigned long *tmp;					\
	tmp = buff1;				\
	buff1 = buff2;				\
	buff2 = tmp;				\
} while (0);

static void		swap_buffers(unsigned long **buff1, unsigned long **buff2)
{
	unsigned long *tmp;

	tmp = *buff1;
	*buff1 = *buff2;
	*buff2 = tmp;
}

static unsigned long	*bit_sort_pass(unsigned long *input_array,
										unsigned long *output_array,
										unsigned long nb_items,
										unsigned long shift)
{
	int counters[2] = {0};
	int offset_table[2] = {0};
	int i;
	unsigned char c;

	i = 0;
	while (i < nb_items)
	{
		c = (input_array[i] >> shift) & 1;
		counters[c]++;
		i++;
	}

	offset_table[1] = counters[0];

	i = 0;
	while (i < nb_items)
	{
		c = (input_array[i] >> shift) & 1;
		if (c)
			write(1, "ra\n", 3);
		else
			write(1, "pb\n", 3);
		output_array[offset_table[c]++] = input_array[i];
		i++;
	}
	while (counters[0]--)
		write(1, "pa\n", 3);

	return output_array;
}

unsigned long *bit_sort(unsigned long *input_array,
						unsigned long nb_items,
						unsigned long nb_bits_to_sort)
{
	unsigned long *buffer;
	int shift = 0;

	buffer = malloc(nb_items * sizeof(unsigned long));
	shift = 0;
	while (shift < nb_bits_to_sort)
	{
		buffer = bit_sort_pass(input_array, buffer, nb_items, shift);
		/*swap_buffers(&buffer, &input_array);*/
		PRINT_ARRAY(buffer, nb_items);
		SWAP_BUFFERS(buffer, input_array);
		shift++;
	}
	free(buffer);
	return (input_array);
}
