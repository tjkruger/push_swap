/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_node_to_correct_pos.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:25:08 by tjkruger          #+#    #+#             */
/*   Updated: 2025/03/11 14:52:55 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/list.h"
#include "../includes/utils.h"
#include <stdio.h>

int	find_best_bigger_neighbour(t_dnode *stack_b, int value)
{
	t_dnode	*current;
	t_dnode	*best_fit;
	int		best_fit_index;
	int		index;

	best_fit = NULL;
	best_fit_index = -1;
	index = 0;
	current = stack_b;
	while (current)
	{
		if (current->value > value && (!best_fit
				|| current->value < best_fit->value))
		{
			best_fit = current;
			best_fit_index = index;
		}
		current = current->next;
		index++;
	}
	if (best_fit_index == -1)
		return (0);
	return (best_fit_index);
}

// int	find_best_smaller_neighbour(t_dnode *stack_b, int value)
// {
// 	t_dnode	*current;
// 	t_dnode	*best_fit;
// 	int		best_fit_index;
// 	int		index;

// 	best_fit = NULL;
// 	best_fit_index = -1;
// 	index = 0;
// 	current = stack_b;
// 	while (current)
// 	{
// 		if (current->value < value && (!best_fit
// 				|| current->value > best_fit->value))
// 		{
// 			best_fit = current;
// 			best_fit_index = index;
// 		}
// 		current = current->next;
// 		index++;
// 	}
// 	if (best_fit_index == -1)
// 		return (0);
// 	return (best_fit_index);
// }

void	move_top_a(t_dnode **list_a, t_dnode **list_b)
{
	t_dnode	*bnode;

	bnode = find_best_node_to_push(*list_a, *list_b);
	while (*list_a != bnode)
	{
		if (bnode->index <= list_size(*list_a) / 2)
			ra(list_a);
		else
			rra(list_a);
	}
}

void	move_cor_pos_b(t_dnode **list_a, t_dnode **list_b, t_dnode *best_node)
{
	int	best_index;
	int	size_b;
	int	best_index_value;

	size_b = list_size(*list_b);
	// obsolete
	if (!list_b || !(*list_b)) 
	{
		pb(list_a, list_b);
		return;
	}

	find_best_position_in_b(*list_b, best_node->value, size_b, &best_index);
	// ft_printf("best index: %i\n", best_index);
	// print_list(*list_a, *list_b);
	// ft_printf("---------------\n");
	best_index_value = get_node_at_index(*list_b, best_index)->value;
	while (get_node_at_index(*list_b, 0)->value != best_index_value)
	{
		if (best_index < size_b / 2)
			rb(list_b);
		else
			rrb(list_b);
	}
	pb(list_a, list_b);
}
