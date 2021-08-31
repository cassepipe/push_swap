#ifndef CHECK_DUPLICATES_H
# define CHECK_DUPLICATES_H

struct s_fat_int
{
	int	num;
	int	offset;
	int	ord;
};

void	error_if_duplicates(struct s_fat_int *array, int nb_items);

#endif /* CHECK_DUPLICATES_H */
