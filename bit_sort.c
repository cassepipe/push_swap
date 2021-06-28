#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "new_int_array.h"

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

#define SWAP_BUFFERS(buff1, buff2)	do {	\
	int *tmp;					\
	tmp = buff1;				\
	buff1 = buff2;				\
	buff2 = tmp;				\
} while (0);

void swap_buffers(void **buff1, void **buff2)
{
	void *tmp;

	tmp = *buff1;
	*buff1 = buff2;
	*buff2 = tmp;
}

int *bit_sort_int_pass(int *input_array, int *output_array, int nb_items, int shift)
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
int *bit_sort_int_sign_bit(int *input_array, int *output_array, int nb_items)
{
	int counters[2] = {0};
	int offset_table[2];
	int i;
	int nb_negative_values = 0;
	unsigned char c;

	i = 0;
	while (i < nb_items)
	{
		c = (input_array[i] >> (sizeof(int)*8 - 1)) & 1;
		counters[c]++;
		i++;
	}

	nb_negative_values = counters[1];

	offset_table[0] = nb_negative_values;
	offset_table[1] = 0;

	i = 0;
	while (i < nb_items)
	{
		c = (input_array[i] >> (sizeof(int)*8 - 1)) & 1;
		if (c)
			write(1, "pb\n", 3);
		else
			write(1, "ra\n", 3);
		output_array[offset_table[c]++] = input_array[i];
		i++;
	}
	while (counters[1]--)
		write(1, "pa\n", 3);

	return output_array;
}


int *bit_sort_int(int *int_array, int nb_items, int nb_bits_to_sort)
{
	int *buffer;
	int shift = 0;

	buffer = new_int_array(nb_items);
	shift = 0;
	while (shift < nb_bits_to_sort)
	{
		buffer = bit_sort_int_pass(int_array, buffer, nb_items, shift);
		SWAP_BUFFERS(buffer, int_array);
		shift++;
	}
	buffer = bit_sort_int_sign_bit(int_array, buffer, nb_items);
	SWAP_BUFFERS(buffer, int_array);

	free(buffer);
	return (int_array);

}
