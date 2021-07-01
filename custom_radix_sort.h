/* This file was automatically generated.  Do not edit! */
#undef INTERFACE
typedef struct array_member array_member;
struct array_member *radix_sort_int(struct array_member *array,int nb_items);
struct array_member *radix_sort_int_last_pass(struct array_member *input_array,struct array_member *output_array,int nb_items,int shift);
struct array_member *radix_sort_int_pass(struct array_member *input_array,struct array_member *output_array,int nb_items,int shift);
struct array_member {
	int	num;
	int	offset;
	int	ord;
};
