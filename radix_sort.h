#include <stdlib.h>
#include <stdio.h>

void print_bits(size_t const size, void const * const ptr);
int *radix_sort_int_pass(int *input_array, int *buffer, int nb_items, int shift);
int *radix_sort_int(int *input_array, int nb_items);
int *bit_sort_int(int *int_array, int nb_items, int nb_bits_to_sort);
