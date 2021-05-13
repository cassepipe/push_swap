#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define ENDCOLOR "\033[0m"
#define GREEN "\033[92m"
#define RED "\033[31m"

void	print_two_stacks(int *a, int siza, int *b, int sizb);
bool	check_ordered(int *numbers, int size);

int 	main(int argc, char **argv)
{
	int	numbers[argc - 1];
	int i;

	argv++;
	argc--;
	i = 0;
	while (i < argc)
	{
		numbers[i] = atoi(argv[i]);
		i++;
	}

	print_two_stacks(numbers, argc,  numbers, argc - 2);
	if (check_ordered(numbers, argc))
		printf(GREEN "OK" ENDCOLOR "\n");
	else
		printf(RED "KO" ENDCOLOR "\n");

	return (0);
}

void	print_two_stacks(int *a, int siza, int *b, int sizb)
{
	int  i;
	int  y;

	i = 0;
	y = 0;
	siza = siza < 0 ? 0 : siza;
	sizb = sizb < 0 ? 0 : sizb;
	if (siza > sizb)
		while (siza > sizb)
		{
			printf("\t%i", a[i]);
			puts("\n");
			i++;
			siza--;
		}
	else
		while (sizb > siza)
		{
			printf("\t\t%i",b[i]);
			puts("\n");
			i++;
			sizb--;
		}
	while (siza-- && sizb--)
	{
		printf("\t%i", a[i]);
		printf("\t%i", b[i]);
		puts("\n");
		i++;
	}
}

bool	check_ordered(int *numbers, int size)
{
	int *next_num;
	int *end;

	next_num = numbers + 1;
	end = numbers + size;
	while (next_num != end)
	{
		if (*numbers > *next_num)
			break;
		numbers++;
		next_num++;
	}
	if (next_num == end)
		return (true);
	else
		return (false);
}
