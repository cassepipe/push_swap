#include <unistd.h>

void	pb()
{
	write(STDOUT_FILENO, "pb\n", 3);
}

void	ra()
{
	write(STDOUT_FILENO, "ra\n", 3);
}

void	rra()
{
	write(STDOUT_FILENO, "rra\n", 4);
}

void	pa()
{
	write(STDOUT_FILENO, "pa\n", 3);
}

void sa()
{
	write(STDOUT_FILENO, "sa\n", 3);
}
