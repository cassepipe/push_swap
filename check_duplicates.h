/* This file was automatically generated.  Do not edit! */
#undef INTERFACE
typedef struct fat_int fat_int;
struct fat_int {
	int	num;
	int	offset;
	int	ord;
};
void error_if_duplicates(struct fat_int *array,int nb_items);
