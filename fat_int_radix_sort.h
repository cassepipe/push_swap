/* This file was automatically generated.  Do not edit! */
#undef INTERFACE
typedef struct fat_int fat_int;
struct fat_int *fat_int_radix_sort(struct fat_int *array,int nb_items);
struct fat_int *radix_sort_int_last_pass(struct fat_int *input_array,struct fat_int *output_array,int nb_items,int shift);
struct fat_int *radix_sort_int_pass(struct fat_int *input_array,struct fat_int *output_array,int nb_items,int shift);
struct fat_int {
	int	num;
	int	offset;
	int	ord;
};
