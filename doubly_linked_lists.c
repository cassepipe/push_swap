#include <stdlib.h>
#include <stdio.h>

typedef struct	s_stack	{
	int				num;
	struct s_stack	*prev;
	struct s_stack	*next;
} t_stack;

typedef struct	s_dll {
	struct s_stack	**head;
	int				size;
} t_dll;

t_stack	*dll_new_node(int n)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = n;
	new->prev = new;
	new->next = new;
	return (new);
}

t_stack **dll_append(t_stack **head, t_stack *node)
{
	t_stack *last;

	if (head)
	{
		if (*head)
		{
			last = (*head)->prev;
			last->next = node;
			node->prev = last;
			node->next = *head;
			(*head)->prev = node;
		}
		else
			*head = node;
	}

	return (head);
}

void	dll_rotate(t_stack **head)
{
	if (head && *head)
		*head = (*head)->next;
}

void	dll_revrotate(t_stack **head)
{
	if (head && *head)
		*head = (*head)->prev;
}


t_stack	*dll_pop(t_stack **head)
{
	t_stack	*ret;

	(*head)->next->prev = (*head)->prev;
	(*head)->prev->next = (*head)->next;
	ret = (*head);
	*head = (*head)->next;
	return (ret);
}

void	dll_push(t_stack **dll, t_stack *node)
{
	if (dll && *dll)
	{
		dll_append(dll, node);
		dll_revrotate(dll);
	}
}

void	dll_swaptop(t_stack **head)
{
	t_stack *tmp;
	t_stack *second_element;
	if (head && *head)
	{
		tmp = dll_pop(head);
		/*printf("Popped struct at %lu { .prev =  %lu, .next = %lu\n", tmp, tmp->prev, tmp->next);*/
		second_element = ((*head)->next);
		dll_append(&second_element, tmp);
	}
}

void	dll_poppush(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	if (a && *a && b && *b)
	{
		tmp = dll_pop(a);
		dll_push(b, tmp);
	}
}

void	free_dll(t_stack **list, int nmemb)
{
	t_stack *node;

	if (list)
	{
		if (*list)
		{
			node = (*list)->next;
			while (--nmemb)
			{
				node = node->next;
				free(node->prev);
			}
			free(*list);
		}
	}
}

void	print_dll(t_stack **a, int size_a)
{
	size_a = size_a > 0 ? size_a: 0;
	while (size_a--)
	{
		printf("\t%i", (*a)->num);
		printf("\n");
		*a = (*a)->next;
	}
}
