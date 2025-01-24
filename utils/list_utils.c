/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:34:28 by tjkruger          #+#    #+#             */
/*   Updated: 2025/01/24 17:17:27 by tjkruger         ###   ########.fr       */
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
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	add_to_list_back(t_dnode **list_a, t_dnode *new_node)
{
	t_dnode	*last;

	if (!list_a || !new_node)
		return ;
	if (!*list_a)
	{
		*list_a = new_node;
	}
	else
	{
		last = *list_a;
		while (last->next)
			last = last->next;
		last->next = new_node;
		new_node->prev = last;
	}
}

void	print_list(t_dnode *list_a, t_dnode *list_b)
{
	ft_printf("Init a and b\n");
	while (list_a || list_b)
	{
		if (list_a)
		{
			ft_printf("%d", list_a->value);
			list_a = list_a->next;
		}
		else
			ft_printf("_");
		ft_printf(" ");
		if (list_b)
		{
			ft_printf("%d", list_b->value);
			list_b = list_b->next;
		}
		else
			ft_printf(" ");
		ft_printf("\n");
	}
	ft_printf("- -\n");
	ft_printf("a b\n");
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
