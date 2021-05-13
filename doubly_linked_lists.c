#include <stdlib.h>

typedef	struct	s_stack	{
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

void	dll_append(t_stack **head, t_stack *node)
{
	t_stack *last;

	if (!head)
		*head = node;
	last = (*head)->prev;
	last->next = node;
	node->prev = last;
	node->next = *head;
	(*head)->prev = node;
}

void	dll_rotate(t_stack **head)
{
	*head = (*head)->next;
}

void	dll_revrotate(t_stack **head)
{
	*head = (*head)->prev;
}

void	dll_swaptop(t_stack **head)
{
	(*head)->next->prev = (*head)->prev;
	(*head)->prev->next = (*head)->next;
	dll_append(&(*head)->next, *head);
	*head = (*head)->next;
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
	dll_append(dll, node);
	dll_revrotate(dll);
}


void	dll_poppush(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	tmp = dll_pop(a);
	dll_push(b, tmp);
}

