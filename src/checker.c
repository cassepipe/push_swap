#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft/get_next_line.h"
#include "libft/ft_printf/ft_printf.h"
#include "checker.h"

static t_stack	*parse_numbers_or_error(char **num_strings, int nb_items)
{
	int				i;
	int				num;
	bool			parse_error;
	t_stack			*stack;

	stack = new_empty_stack();
	if (!stack)
		exit(EXIT_FAILURE);
	i = 0;
	parse_error = false;
	while (i < nb_items && parse_error == false)
	{
		num = atoi_error(*num_strings++, &parse_error);
		stack_append(stack, dll_new_node(num));
		i++;
	}
	if (parse_error)
	{
		free_stack(stack);
		write(STDERR_FILENO, "Error\n", sizeof("Error\n"));
		exit(EXIT_FAILURE);
	}
	return (stack);
}

void	put_stack_ordered(t_stack stack)
{
	if (is_stack_sorted(stack))
		ft_printf(GREEN "OK" ENDCOLOR "\n");
	else
		ft_printf(RED "KO" ENDCOLOR "\n");
}

int 	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	argv++;
	argc--;
	a = parse_numbers_or_error(argv, argc);
	error_if_duplicates_in_stack(a);
	b = new_empty_stack();
	if (!a || !b)
		return (EXIT_FAILURE);
	loop_exec_stack_ops(a, b);
	if (b->size == 0)
		put_stack_ordered(*a);
	else
		ft_printf(RED "KO" ENDCOLOR "\n");
	free_stack(a);
	free_stack(b);
	return (0);
}
