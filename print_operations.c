#include <unistd.h>

void	pb()
{
	write(1, "pb\n", 3);
}

void	ra()
{
	write(1, "ra\n", 3);
}

void	rra()
{
	write(1, "rra\n", 4);
}

void	pa()
{
	write(1, "pa\n", 3);
}

void sa()
{
	write(1, "sa\n", 3);
}
