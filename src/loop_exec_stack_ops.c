#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "loop_exec_stack_ops.h"

static void	inverse_stack_stack_poppush(t_stack *dst, t_stack *src)
{
	stack_poppush(src, dst);
}

static const struct s_fat_token {
	const char	*token;
	void		(*execute_instruction)();
} token_table[] =
{
	{"rra\n", &stack_revrotate},
	{"rrb\n", &stack_revrotate},
	{"rrr\n", &stack_revrotate},
	{"ra\n", &stack_rotate},
	{"rb\n", &stack_rotate},
	{"rr\n", &stack_rotate},
	{"sa\n", &stack_swaptop},
	{"sb\n", &stack_swaptop},
	{"ss\n", &stack_swaptop},
	{"pa\n", &inverse_stack_stack_poppush},
	{"pb\n", &inverse_stack_stack_poppush},
};

static void	bs_fun(char *line, unsigned long i, t_stack *a, t_stack *b)
{
	if (line[1] == 'a' || line[2] == 'a')
		token_table[i].execute_instruction(a, b);
	else if (line[1] == 'b' || line[2] == 'b')
		token_table[i].execute_instruction(b, a);
	else
	{
		token_table[i].execute_instruction(a, b);
		token_table[i].execute_instruction(b, a);
	}
}

static void	die_free(t_stack *stack1, t_stack *stack2)
{
	free_stack(stack1);
	free_stack(stack2);
	write(STDERR_FILENO, "Error\n", sizeof("Error\n"));
	exit(EXIT_FAILURE);
}

void	loop_exec_stack_ops(t_stack *a, t_stack *b)
{
	char			*line;
	unsigned long	i;

	while (get_next_line_with_newline(STDIN_FILENO, &line) > 0)
	{
		i = 0;
		while (i < sizeof(token_table) / sizeof(token_table[0]))
		{
			if (!ft_strcmp(token_table[i].token, line))
			{
				bs_fun(line, i, a, b);
				break ;
			}
			i++;
		}
		free(line);
		if (i == sizeof(token_table) / sizeof(token_table[0]))
			die_free(a, b);
	}
	free(line);
}
