#include <stdio.h>

#define ENDCOLOR "\033[0m"
#define GREEN "\033[92m"
#define RED "\033[31m"

#define SWAP_BUFFERS(buff1, buff2)	do {	\
	int *tmp;				\
	tmp = buff1;				\
	buff1 = buff2;				\
	buff2 = tmp;				\
} while (0);

#define PRINT_FAT_INT_ARRAY(arr, size) do { \
	for(int i = 0; i < size; i++)	\
	printf("%i\t", arr[i].num);		\
	printf("\n");				\
} while (0);				\

#define PRINT_ARRAY(arr, size) do { \
	for(int i = 0; i < size; i++)	\
	printf("%i\t", arr[i]);		\
	printf("\n");				\
} while (0);					\

#define PRINT_ARRAY_HEX(array, size)	do {	\
	int i = 0;				\
	while (i < size)			\
	{					\
		printf("%X\t", array[i]);	\
		i++;				\
	}					\
	printf("\n");				\
} while (0);

#define PRINT_TWO_STACKS(A, B) do { \
	/*printf("\x1b[2J");*/	\
	/*printf("\x1b[H");*/	\
	printf("\n\tSTACK A\n--------------------------\n");	\
	print_stack(*A);					\
	printf("\n\tSTACK B\n--------------------------\n");   	\
	print_stack(*B);					\
} while (0);
