
#include <stdlib.h>
#include <stdio.h>
#include "new_int_array.h"

#define PRINT_INT_ARRAY(array, size)	do {	\
	int i = 0;						\
	while (i < size)				\
	{								\
		printf("%i\t", array[i].num);	\
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
	struct array_member *tmp;					\
	tmp = buff1;				\
	buff1 = buff2;				\
	buff2 = tmp;				\
} while (0);

struct array_member {
	int	num;
	int	offset;
	int	ord;
};

struct array_member *radix_sort_int_pass(struct array_member *input_array,
										struct array_member *output_array,
										int nb_items,
										int shift)
{
	int counters[256] = {0};
	int offset_table[256] = {0};
	int i;
	unsigned char c;

	i = 0;
	while (i < nb_items)
	{
		c = (input_array[i].num >> shift) & 0xff;
		counters[c]++;
		i++;
	}

	i = 1;
	while (i < 256)
	{
		offset_table[i] = offset_table[i-1] + counters[i-1];
		i++;
	}

	i = 0;
	while (i < nb_items)
	{
		c = (input_array[i].num >> shift) & 0xff;
		output_array[offset_table[c]++] = input_array[i];
		i++;
	}

	return output_array;
}

struct array_member *radix_sort_int_last_pass(struct array_member *input_array,
											struct array_member *output_array,
											int nb_items,
											int shift)
{
	int counters[256] = {0};
	int offset_table[256];
	int i;
	int nb_negative_values = 0;
	unsigned char c;

	i = 0;
	while (i < nb_items)
	{
		c = (input_array[i].num >> shift) & 0xff;
		counters[c]++;
		i++;
	}

	i = 128;
	while (i < 256)
	{
		nb_negative_values += counters[i];
		i++;
	}

	offset_table[0] = nb_negative_values;
	offset_table[255] = 0;

	i = 1;
	while (i < 128)
	{
			offset_table[i] = offset_table[i-1] + counters[i - 1];
			i++;
	}
	i = 0;
	while (i < 127)
	{
        offset_table[254-i] = offset_table[255-i] + counters[255-i];
		i++;
	}
	i = 0;
	while (i < nb_items)
	{
		c = (input_array[i].num >> shift) & 0xff;
		output_array[offset_table[c]++] = input_array[i];
		i++;
	}

	return output_array;
}


struct array_member *radix_sort_int(struct array_member *array, int nb_items)
{
	struct array_member *buffer;
	int shift = 0;

	buffer = malloc(nb_items * sizeof(struct array_member));
	while (shift < 24)
	{
		buffer = radix_sort_int_pass(array, buffer, nb_items, shift);
		SWAP_BUFFERS(buffer, array);
		shift += 8;
	}
	buffer = radix_sort_int_last_pass(array, buffer, nb_items, shift);

	free(array);
	return (buffer);

}
