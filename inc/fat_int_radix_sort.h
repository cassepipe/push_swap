#ifndef FAT_INT_RADIX_SORT_H
# define FAT_INT_RADIX_SORT_H

struct s_fat_int
{
	int	num;
	int	offset;
	int	ord;
};

struct s_fat_int	*fat_int_radix_sort(struct s_fat_int *array, int nb_items);

#endif /* FAT_INT_RADIX_SORT_H */
