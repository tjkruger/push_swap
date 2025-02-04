/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:37:36 by tjkruger          #+#    #+#             */
/*   Updated: 2025/02/04 16:33:48 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/list.h"

t_dnode	*find_largest(t_dnode *list_a)
{
	t_dnode	*largest_node;

	largest_node = list_a;
	while (list_a->next)
	{
		if (list_a->value > largest_node->value)
			largest_node = list_a;
		list_a = list_a->next;
	}
	return (largest_node);
}

t_dnode	*find_smallest(t_dnode *list_a)
{
}

void	push_to_b(t_dnode **list_a, t_dnode **list_b)
{
	t_dnode	*smallest;
	t_dnode	*largest;
	t_dnode	*node;

	while (*list_a)
	{
		smallest = find_smallest(*list_a);
		largest = find_largest(*list_a);
		node = *list_a;
		if (node == smallest || node == largest)
		{
			pb(list_a, list_b);
			if (*list_b && (*list_b)->next)
				rotate_list_b(list_b);
		}
		else
		{
			move_to_correct_position(list_b, node);
			pb(list_a, list_b);
		}
	}
}

void	push_back_to_a(t_dnode **list_a, t_dnode **list_b)
{
	while (*list_b)
		pa(list_a, list_b);
}
