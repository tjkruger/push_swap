/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:34:28 by tjkruger          #+#    #+#             */
/*   Updated: 2025/02/24 14:09:48 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/list.h"
#include "../includes/utils.h"
#include <stdlib.h>

t_dnode	*create_node(int value)
{
	t_dnode	*new_node;

	new_node = malloc(sizeof(t_dnode));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void add_to_list_back(t_dnode **list_a, t_dnode *new_node)
{
    t_dnode *last;
    int i = 0;

    if (!list_a || !new_node)
        return;

    if (!*list_a)
    {
        *list_a = new_node;
        new_node->index = 0;
    }
    else
    {
        last = *list_a;
        while (last->next)
        {
            last = last->next;
            i++;
        }
        last->next = new_node;
        new_node->index = i + 1;
    }
}

void	print_list(t_dnode *list_a, t_dnode *list_b)
{
	(void)list_a;
	(void)list_b;
	// while (list_a || list_b)
	// {
	// 	if (list_a)
	// 	{
	// 		ft_printf("%d, %d", list_a->value, list_a->index);
	// 		list_a = list_a->next;
	// 	}
	// 	else
	// 		ft_printf(" ");
	// 	ft_printf(" ");
	// 	if (list_b)
	// 	{
	// 		ft_printf("%d, %d", list_b->value, list_b->index);
	// 		list_b = list_b->next;
	// 	}
	// 	else
	// 		ft_printf(" ");
	// 	ft_printf("\n");
	// }
	// ft_printf("-     -\n");
	// ft_printf("a     b\n");
}

void	free_list(t_dnode **list_a)
{
	t_dnode	*temp;

	if (!list_a || !*list_a)
		return ;
	while (*list_a)
	{
		temp = *list_a;
		*list_a = (*list_a)->next;
		free(temp);
	}
}
