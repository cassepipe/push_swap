#include <stdbool.h>
#include <limits.h>
#include "libft/libft.h"
#include "atoi_error.h"

static bool	parse_sign(const char **ptr)
{
	int	sign;

	sign = 0;
	while (**ptr == '+' || **ptr == '-')
	{
		if (**ptr == '-')
			sign++;
		(*ptr)++;
	}
	return (sign % 2);
}

static int	atoi_error(const char *ptr, bool *error)
{
	long	result;
	bool	neg;

	*error = false;
	result = 0;
	if (*ptr == '\0')
		*error = true;
	while (ft_isspace(*ptr))
		ptr++;
	neg = parse_sign(&ptr);
	while (ft_isdigit(*ptr) && result <= 2147483648)
	{
		result *= 10;
		result += *ptr - '0';
		ptr++;
	}
	if ((*ptr && !ft_isspace(*ptr)) || result > INT_MAX)
		*error = true;
	if (neg && result == 2147483648)
		*error = false;
	if (neg)
		return (-result);
	else
		return (result);
}

struct fat_int	*parse_numbers_or_error(char **num_strings, int nb_items)
{
	int				i;
	int				num;
	bool			parse_error;
	struct fat_int	*array;

	array = malloc(nb_items * sizeof(struct fat_int));
	if (!array)
		exit(EXIT_FAILURE);
	i = 0;
	parse_error = false;
	while (i < nb_items && parse_error == false)
	{
		num = atoi_error(*num_strings++, &parse_error);
		array[i].num = num;
		array[i].offset = i;
		i++;
	}
	if (parse_error)
	{
		free(array);
		write(STDERR_FILENO, "Error\n", sizeof("Error\n"));
		exit(EXIT_FAILURE);
	}
	return (array);
}
