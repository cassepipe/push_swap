#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "bit_sort.h"

static void	die(int *to_free)
{
	free(to_free);
	exit(EXIT_FAILURE);
}

static void	swap_buffers(int **buff1, int **buff2)
{
	int	*tmp;

	tmp = *buff1;
	*buff1 = *buff2;
	*buff2 = tmp;
}

static void	ra_or_pb(unsigned char c)
{
	if (c)
		ra();
	else
		pb();
}

static int	*bit_sort_pass(int *input_array,
							int *output_array,
							int nb_items,
							int shift)
{
	int				counters[2];
	int				offset_table[2];
	int				i;
	unsigned char	c;

	ft_bzero(counters, 2 * sizeof(int));
	ft_bzero(offset_table, 2 * sizeof(int));
	i = 0;
	while (i < nb_items)
	{
		c = (input_array[i++] >> shift) & 1;
		counters[c]++;
	}
	offset_table[1] = counters[0];
	i = 0;
	while (i < nb_items)
	{
		c = (input_array[i] >> shift) & 1;
		ra_or_pb(c);
		output_array[offset_table[c]++] = input_array[i];
		i++;
	}
	while (counters[0]--)
		pa();
	return (output_array);
}

int	*bit_sort_raw(int *input_array,
		int nb_items,
		int max)
{
	int	*buffer;
	int	shift;
	int	nb_bits_to_sort;

	nb_bits_to_sort = 0;
	while (max >> nb_bits_to_sort)
		nb_bits_to_sort++;
	buffer = malloc(nb_items * sizeof(int));
	if (!buffer)
		die(buffer);
	shift = 0;
	while (shift < nb_bits_to_sort)
	{
		buffer = bit_sort_pass(input_array, buffer, nb_items, shift);
		swap_buffers(&buffer, &input_array);
		shift++;
	}
	free(buffer);
	return (input_array);
}

/*int	*bit_sort_sign_pass(int *input_array, int *output_array, int nb_items)*/
/*{*/
/*    int				counters[2] = {0};*/
/*    int				offset_table[2];*/
/*    int				i;*/
/*    int				nb_negative_values;*/
/*    unsigned char	c;*/

/*    i = 0;*/
/*    while (i < nb_items)*/
/*    {*/
/*        c = (input_array[i] >> (sizeof(int) * 8 - 1)) & 1;*/
/*        counters[c]++;*/
/*        i++;*/
/*    }*/
/*    nb_negative_values = counters[1];*/
/*    offset_table[0] = nb_negative_values;*/
/*    offset_table[1] = 0;*/
/*    i = 0;*/
/*    while (i < nb_items)*/
/*    {*/
/*        c = (input_array[i] >> (sizeof(int) * 8 - 1)) & 1;*/
/*        if (c)*/
/*            write(1, "pb\n", 3);*/
/*        else*/
/*            write(1, "ra\n", 3);*/
/*        output_array[offset_table[c]++] = input_array[i];*/
/*        i++;*/
/*    }*/
/*    while (counters[1]--)*/
/*        write(1, "pa\n", 3);*/
/*    return (output_array);*/
/*}*/

/*int	*bit_sort_int(int *int_array, int nb_items, int nb_bits_to_sort)*/
/*{*/
/*    int	*buffer;*/
/*    int	shift;*/

/*    buffer = new_int_array(nb_items);*/
/*    if (!buffer)*/
/*        die(int_array);*/
/*    shift = 0;*/
/*    while (shift < nb_bits_to_sort)*/
/*    {*/
/*        buffer = bit_sort_pass(int_array, buffer, nb_items, shift);*/
/*        SWAP_BUFFERS(buffer, int_array);*/
/*        shift++;*/
/*    }*/
/*    buffer = bit_sort_sign_pass(int_array, buffer, nb_items);*/
/*    swap_buffers(&buffer, &int_array);*/
/*    free(buffer);*/
/*    return (int_array);*/
/*}*/
