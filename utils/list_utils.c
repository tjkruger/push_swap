/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:34:28 by tjkruger          #+#    #+#             */
/*   Updated: 2025/01/21 15:06:53 by tjkruger         ###   ########.fr       */
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

void	add_to_list_back(t_dnode **list, t_dnode *new_node)
{
	t_dnode	*last;

	if (!list || !new_node)
		return ;
	if (!*list)
	{
		*list = new_node;
	}
	else
	{
		last = *list;
		while (last->next)
			last = last->next;
		last->next = new_node;
		new_node->prev = last;
	}
}

void	print_list(t_dnode *list)
{
	if (!list)
	{
		ft_printf("List is empty\n");
		return ;
	}
	while (list)
	{
		ft_printf("%d", list->value);
		if (list->next)
			ft_printf(" -> ");
		list = list->next;
	}
	ft_printf("\n");
}

void	free_list(t_dnode **list)
{
	t_dnode	*temp;

	if (!list || !*list)
		return ;
	while (*list)
	{
		temp = *list;
		*list = (*list)->next;
		free(temp);
	}
}
