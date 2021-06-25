#include <stdlib.h>
#include <stdio.h>

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

// Assumes little endian
void print_bits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

int *radix_sort_int_pass(int *input_array, int nb_items, int shift)
{
	int counters[256] = {0};
	int offset_table[256] = {0};
	int *output_array;
	int i;
	unsigned char c;
	printf("Pass number %i, shifting bits by %i\n", shift / 8 + 1, shift);

	i = 0;
	while (i < nb_items)
	{
		c = (input_array[i] >> shift) & 0xff;
		printf("(%i >> %i) & 0xff = %i\n", input_array[i], shift, c);
		counters[c]++;
		i++;
	}
	puts("Counters table :\t");
	PRINT_INT_ARRAY(counters, 256);

	i = 1;
	while (i < 256)
	{
		offset_table[i] = offset_table[i-1] + counters[i-1];
		i++;
	}
	puts("Offset table :\t");
	PRINT_INT_ARRAY(offset_table, 256);

	output_array = calloc(nb_items, sizeof(int));
	i = 0;
	while (i < nb_items)
	{
		c = (input_array[i] >> shift) & 0xff;
		printf("output_array[offset_table[%i]] = input_array[%i]\n", c, i);
		output_array[offset_table[c]++] = input_array[i];
		i++;
	}

	return output_array;
}

int *radix_sort_int(int *input_array, int nb_items)
{
	int *buffer;
	int *tmp;
	int shift = 0;

	buffer = input_array;
	while (shift < sizeof(int) * 8)
	{
		tmp = buffer;
		buffer = radix_sort_int_pass(buffer, nb_items, shift);
		printf("PASS %i:\n", shift / 8 + 1);
		PRINT_INT_ARRAY(buffer, nb_items);
		PRINT_INT_ARRAY_HEX(buffer, nb_items);
		free(tmp);
		shift += 8;
	}
	//output_array = radix_sort_int_last_pass(input_array, nb_items, shift);

	return buffer;

}

/*int main(int argc, char **argv)*/
/*{*/
	/*argc--;*/
	/*argv++;*/
	/*int *input_array;*/
	/*int *output_array;*/

	/*input_array = malloc(argc * sizeof(int));*/
	/*int i = 0;*/
	/*while (i < argc)*/
	/*{*/
		/*input_array[i] = atoi(argv[i]);*/
		/*i++;*/
	/*}*/

	/*puts("input_array is ");*/
	/*PRINT_INT_ARRAY(input_array, argc);*/
	/*output_array = radix_sort_int(input_array, argc);*/
	/*printf("output_array is ");*/
	/*PRINT_INT_ARRAY(output_array, argc);*/
	/*free(output_array);*/
/*}*/
