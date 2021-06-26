#include <stdlib.h>

int 	*new_int_array(int size)
{
	int *new_array;

	new_array = malloc(size * sizeof(int));
	if (!new_array)
		return (NULL);
	return new_array;
}
