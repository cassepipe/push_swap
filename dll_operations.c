#include <stdlib.h>
#include <stdio.h>
#include "dll_operations.h"

t_dllnode	*dll_new_node(int n)
{
	t_dllnode	*new;

	new = malloc(sizeof(t_dllnode));
	if (!new)
		return (NULL);
	new->num = n;
	new->prev = new;
	new->next = new;
	return (new);
}

void	free_dll(t_dllnode **list, int nmemb)
{
	t_dllnode	*node;

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

/*t_dllnode	**dll_append(t_dllnode **head, t_dllnode *node)*/
/*{*/
/*    t_dllnode	*last;*/

/*    if (head)*/
/*    {*/
/*        last = (*head)->prev;*/
/*        last->next = node;*/
/*        node->prev = last;*/
/*        node->next = *head;*/
/*        (*head)->prev = node;*/
/*    }*/
/*    else*/
/*    {*/
/*        *head = node;*/
/*        (*head)->prev = node;*/
/*        (*head)->next = node;*/
/*    }*/
/*    return (head);*/
/*}*/

/*void	dll_rotate(t_dllnode **head)*/
/*{*/
/*    if (head && *head)*/
/*        *head = (*head)->next;*/
/*}*/

/*void	dll_revrotate(t_dllnode **head)*/
/*{*/
/*    if (head && *head)*/
/*        *head = (*head)->prev;*/
/*}*/

/*t_dllnode	*dll_pop(t_dllnode **head)*/
/*{*/
/*    t_dllnode	*ret;*/

/*    (*head)->next->prev = (*head)->prev;*/
/*    (*head)->prev->next = (*head)->next;*/
/*    ret = (*head);*/
/*    *head = (*head)->next;*/
/*    return (ret);*/
/*}*/

/*void	dll_push(t_dllnode **dll, t_dllnode *node)*/
/*{*/
/*    dll_append(dll, node);*/
/*    dll_revrotate(dll);*/
/*}*/

/*void	dll_swaptop(t_dllnode **head)*/
/*{*/
/*    t_dllnode	*tmp;*/
/*    t_dllnode	*second_element;*/

/*    if (head && *head)*/
/*    {*/
/*        tmp = dll_pop(head);*/
/*        second_element = ((*head)->next);*/
/*        dll_append(&second_element, tmp);*/
/*    }*/
/*}*/

/*void	dll_poppush(t_dllnode **a, t_dllnode **b)*/
/*{*/
/*    t_dllnode	*tmp;*/

/*    if (a && *a)*/
/*    {*/
/*        tmp = dll_pop(a);*/
/*        printf("Popped %d out of stack A\n", tmp->num);*/
/*        dll_push(b, tmp);*/
/*    }*/
/*}*/

/*void	print_dll(t_dllnode **a, int size_a)*/
/*{*/
/*    if (a && *a)*/
/*    {*/
/*        if (size_a < 0)*/
/*            size_a = 0;*/
/*        while (size_a--)*/
/*        {*/
/*            printf("\t%i", (*a)->num);*/
/*            printf("\n");*/
/*            *a = (*a)->next;*/
/*        }*/
/*    }*/
/*}*/
