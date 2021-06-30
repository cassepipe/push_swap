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
		printf("%i\t", arr[i].num);		\
	printf("\n");					\
	} while (0);												\

#define PRINT_INT_ARRAY(arr, size) do { \
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

void  put_array_ordered(struct array_member *int_array, size_t size)
{
	int i;

	i = 1;
	while (i < size)
	{
			if (int_array[i].num < int_array[i-1].num)
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
	struct array_member	*array;
	int		*int_array;

	argv++;
	argc--;
	array = malloc(argc * sizeof(struct array_member));
	if (!array)
		return (-1);
	i = 0;
	while (i < argc)
	{
		num = atoi(*argv++);
		array[i].num = num;
		array[i].offset = i;
		i++;
	}
	/*printf("Input :\n");*/
	/*PRINT_ARRAY(array, argc);*/

	array = radix_sort_int(array, argc);

	int_array = malloc(argc * sizeof(int));
	i = 0;
	while (i < argc)
	{
		int_array[array[i].offset] = i;
		i++;
	}

	/*printf("Output :\n");*/
	/*PRINT_INT_ARRAY(int_array, argc);*/


	max = argc - 1;
	i = 0;
	while (max >> i)
		i++;

	int_array = bit_sort_raw(int_array, argc, i);

	/*PRINT_INT_ARRAY(int_array, argc);*/

	free(array);
	free(int_array);

	return (0);
}
