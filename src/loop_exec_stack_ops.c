#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "loop_exec_stack_ops.h"

static void check_end_of_line(char *line, t_stack *A, t_stack *B)
{
	while (*line != '\n' && *line != '\0')
	{
		if (!ft_isspace(*line))
		{
			free_stack(A);
			free_stack(B);
			write(STDERR_FILENO, "Error\n", sizeof("Error\n"));
			exit(EXIT_FAILURE);
		}
		line++;
	}
}

static void	handle_swap(char *line, t_stack *A, t_stack *B)
{
	if (line[1] == 'a')
		stack_swaptop(A);
	else if (line[1] == 'b')
		stack_swaptop(B);
	else if (line[1] == 's')
	{
		stack_swaptop(A);
		stack_swaptop(B);
	}
	else
	{
		free_stack(A);
		free_stack(B);
		write(STDERR_FILENO, "Error\n", sizeof("Error\n"));
		exit(EXIT_FAILURE);
	}
	check_end_of_line(&line[2], A, B);
}

static void	handle_push(char *line, t_stack *A, t_stack *B)
{
	if (line[1] == 'a')
		stack_poppush(B, A);
	else if (line[1] == 'b')
		stack_poppush(A, B);
	else
	{
		free_stack(A);
		free_stack(B);
		write(STDERR_FILENO, "Error\n", sizeof("Error\n"));
		exit(EXIT_FAILURE);
	}
	check_end_of_line(&line[2], A, B);
}

static void	handle_reverse_rotation(char *line, t_stack *A, t_stack *B)
{
	if (line[2] == 'a')
		stack_revrotate(A);
	else if (line[2] == 'b')
		stack_revrotate(B);
	else if (line[2] == 'r')
	{
		stack_revrotate(A);
		stack_revrotate(B);
	}
	else if (line[2] == '\0' || ft_isspace(line[2]))
	{
		stack_rotate(A);
		stack_rotate(B);
	}
	else
	{
		free_stack(A);
		free_stack(B);
		write(STDERR_FILENO, "Error\n", sizeof("Error\n"));
		exit(EXIT_FAILURE);
	}
	check_end_of_line(&line[3], A, B);
}

static void	handle_rotation(char *line, t_stack *A, t_stack *B)
{
	if (line[1] == 'r')
		handle_reverse_rotation(line, A, B);
	else if (line[1] == 'a')
	{
		stack_rotate(A);
		check_end_of_line(&line[2], A, B);
	}
	else if (line[1] == 'b')
	{
		stack_rotate(B);
		check_end_of_line(&line[2], A, B);
	}
	else
	{
		free_stack(A);
		free_stack(B);
		write(STDERR_FILENO, "Error\n", sizeof("Error\n"));
		exit(EXIT_FAILURE);
	}
}

void	loop_exec_stack_ops(t_stack *A, t_stack *B)
{
	char	*line;

	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (line[0] == 's')
			handle_swap(line, A, B);
		else if (line[0] == 'p')
			handle_push(line, A, B);
		else if (line[0] == 'r')
			handle_rotation(line, A, B);
		else if (line[0] == '\0' || ft_isspace(line[0]))
		{
			free(line);
			continue ;
		}
		else
		{
			free_stack(A);
			free_stack(B);
			write(STDERR_FILENO, "Error\n", sizeof("Error\n"));
			exit(EXIT_FAILURE);
		}
		free(line);
	}
	free(line);
}
