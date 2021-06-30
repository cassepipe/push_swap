#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include "dll.h"
#include "stack.h"
#include "radix_sort.h"
#include "new_int_array.h"
#include "libft/get_next_line.h"

#define ENDCOLOR "\033[0m"
#define GREEN "\033[92m"
#define RED "\033[31m"

#define PRINT_ARRAY(arr, size) do { \
	for(int i = 0; i < size; i++)	\
		printf("%li\t", arr[i]);		\
	printf("\n");					\
	} while (0);												\

#define PRINT_TWO_STACKS(A, B) do { \
		printf("\x1b[2J");										\
		printf("\x1b[H");										\
		printf("\n\tSTACK A\n--------------------------\n");	\
		print_stack(*A);										\
		printf("\n\tSTACK B\n--------------------------\n");   	\
		print_stack(*B);										\
		put_dll_ordered(&A->top);								\
	} while (0);

struct s_fat_token {
	char *token;
	void (*operation)(t_dllnode **list);
};

void  put_array_ordered(long *int_array, size_t size)
{
	int i;

	i = 1;
	while (i < size)
	{
			if (int_array[i] < int_array[i-1])
			{
				printf(RED "KO" ENDCOLOR "\n");
				break;
			}
		i++;
	}
	if (i == size)
		printf(GREEN "OK" ENDCOLOR "\n");
}

int 	main(int argc, char **argv)
{
	int		i;
	int		num;
	int 	max;
	int 	min;
	long	*long_array;

	argv++;
	argc--;
	long_array = malloc(argc * sizeof(long));
	if (!long_array)
		return (-1);
	i = 0;
	max = INT_MIN;
	min = INT_MAX;
	while (i < argc)
	{
		num = atoi(*argv++);
		if (num > max)
			max = num;
		if (num < min)
			min = num;
		long_array[i] = num;
		i++;
	}
	i = 0;
	if (min < 0)
		while (i < argc)
		{
			long_array[i] -= min;
			i++;
		}
	max -= min;
	i = 0;
	while (max >> i)
		i++;

	printf("Max is %i\n", max);
	printf("Min is %i\n", min);
	printf("Input :\n");
	PRINT_ARRAY(long_array, argc);

	long_array = (long*)bit_sort((unsigned long*)long_array, argc, i);

	printf("Output :\n");
	PRINT_ARRAY(long_array, argc);
	put_array_ordered(long_array, argc);

	free(long_array);

	return (0);
}
