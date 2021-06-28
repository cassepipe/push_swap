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
		printf("%i\t", arr[i]);		\
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

void  put_array_ordered(int *int_array, int size)
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
	int		*int_array;

	argv++;
	argc--;
	int_array = new_int_array(argc);
	if (!int_array)
		return (-1);
	i = 0;
	max = INT_MIN;
	while (i < argc)
	{
		num = atoi(*argv++);
		if (num > max)
			max = num;
		int_array[i] = num;
		i++;
	}
	i = sizeof(int) * 8 - 1;
	while (((max >> i) & 1) == 0)
		i--;
	i++;

	/*printf("Input :\n");*/
	/*PRINT_ARRAY(int_array, argc);*/

	int_array = bit_sort_int(int_array, argc, i);

	/*printf("Output :\n");*/
	/*PRINT_ARRAY(int_array, argc);*/
	/*put_array_ordered(int_array, argc);*/

	free(int_array);

	return (0);
}
