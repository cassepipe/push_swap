#include <stdlib.h>
#include "libft/libft.h"
#include "fat_int_radix_sort.h"

static void	swap_buffers(struct s_fat_int **buff1, struct s_fat_int **buff2)
{
	struct s_fat_int	*tmp;

	tmp = *buff1;
	*buff1 = *buff2;
	*buff2 = tmp;
}

static void	count(struct s_fat_int *input_array,
							int nb_items,
							int *counters,
							int shift)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (i < nb_items)
	{
		c = (input_array[i++].num >> shift) & 0xff;
		counters[c]++;
	}
}

static struct s_fat_int	*radix_sort_int_pass(struct s_fat_int *input_array,
		struct s_fat_int *output_array,
		int nb_items,
		int shift)
{
	int				counters[256];
	int				offset_table[256];
	int				i;
	unsigned char	c;

	ft_bzero(counters, 256 * sizeof(int));
	ft_bzero(offset_table, 256 * sizeof(int));
	count(input_array, nb_items, counters, shift);
	i = 1;
	while (i < 256)
	{
		offset_table[i] = offset_table[i - 1] + counters[i - 1];
		i++;
	}
	i = 0;
	while (i < nb_items)
	{
		c = (input_array[i].num >> shift) & 0xff;
		output_array[offset_table[c]++] = input_array[i];
		i++;
	}
	return (output_array);
}

static struct s_fat_int	*radix_sort_int_last_pass(struct s_fat_int *input_array,
		struct s_fat_int *output_array,
		int nb_items,
		int shift)
{
	int				counters[256];
	int				offset_table[256];
	int				i;
	unsigned char	c;

	ft_bzero(counters, 256 * sizeof(int));
	count(input_array, nb_items, counters, shift);
	offset_table[0] = 0;
	i = 128;
	while (i < 256)
		offset_table[0] += counters[i++];
	offset_table[255] = 0;
	i = 0;
	while (++i < 128)
		offset_table[i] = offset_table[i - 1] + counters[i - 1];
	i = -1;
	while (++i < 127)
		offset_table[254 - i] = offset_table[255 - i] + counters[255 - i];
	i = 0;
	while (i < nb_items)
	{
		c = (input_array[i].num >> shift) & 0xff;
		output_array[offset_table[c]++] = input_array[i++];
	}
	return (output_array);
}

struct	s_fat_int	*fat_int_radix_sort(struct s_fat_int *array, int nb_items)
{
	struct s_fat_int	*buffer;
	int					shift;

	shift = 0;
	buffer = malloc(nb_items * sizeof(struct s_fat_int));
	if (!buffer)
	{
		free(array);
		exit(EXIT_FAILURE);
	}
	while (shift < 24)
	{
		buffer = radix_sort_int_pass(array, buffer, nb_items, shift);
		swap_buffers(&buffer, &array);
		shift += 8;
	}
	buffer = radix_sort_int_last_pass(array, buffer, nb_items, shift);
	free(array);
	return (buffer);
}
