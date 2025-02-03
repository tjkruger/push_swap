/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:37:36 by tjkruger          #+#    #+#             */
/*   Updated: 2025/02/03 20:42:32 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/list.h"
#include "../includes/utils.h"
#include <stdio.h>

void	put_bunch_over(t_dnode **list_a, t_dnode **list_b)
{
	t_dnode	*smallest_node;
	t_dnode	*node;
	int		i;

	smallest_node = NULL;
	node = *list_a;
	i = 0;
	while (i <= 4 && *list_a)
	{
		while (node)
		{
			if (node->value < smallest_node->value)
				smallest_node = node;
			node = node->next;
		}
		while (*list_a != smallest_node)
		{
			ra(list_a);
		}
		pb(list_a, list_b);
		i++;
	}
}
