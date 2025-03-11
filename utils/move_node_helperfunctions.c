/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_node_helperfunctions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:11:07 by tjkruger          #+#    #+#             */
/*   Updated: 2025/03/11 11:12:08 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ft_printf.h"
#include "../includes/list.h"
#include "../includes/utils.h"

t_dnode	*get_node_at_index(t_dnode *node, int index)
{
	int	i;

	i = 0;
	while (node && i < index)
	{
		node = node->next;
		i++;
	}
	return (node);
}

int	list_size(t_dnode *list)
{
	int	counter;

	counter = 0;
	while (list)
	{
		counter++;
		list = list->next;
	}
	return (counter);
}
