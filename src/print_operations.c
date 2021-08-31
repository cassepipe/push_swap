#include <unistd.h>

void	pb(void)
{
	write(STDOUT_FILENO, "pb\n", 3);
}

void	ra(void)
{
	write(STDOUT_FILENO, "ra\n", 3);
}

void	rra(void)
{
	write(STDOUT_FILENO, "rra\n", 4);
}

void	pa(void)
{
	write(STDOUT_FILENO, "pa\n", 3);
}

void	sa(void)
{
	write(STDOUT_FILENO, "sa\n", 3);
}
