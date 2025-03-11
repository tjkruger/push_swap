/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:03:17 by tjkruger          #+#    #+#             */
/*   Updated: 2025/03/11 13:57:06 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/list.h"
#include "../includes/utils.h"
#include <stdio.h>

int	get_moves_to_top(int index, int size)
{
	if (index <= size / 2)
		return (index);
	else
		return (size - index);
}

int	calculate_moves(int index, int size)
{
	if (index <= size / 2)
		return (index);
	return (size - index);
}

int	find_best_position_in_b(t_dnode *stack_b, int value, int size_b, int *best_index)
{
	int	moves_b;

	*best_index = find_best_bigger_neighbour(stack_b, value);
	moves_b = calculate_moves(*best_index, size_b);
	return (moves_b);
}


int	get_total_moves(t_dnode *list_a, t_dnode *list_b, t_dnode *node, int index)
{
	int	moves_a;
	int	moves_b;
	int	size_a;
	int	size_b;
	int	best_index;

	size_a = list_size(list_a);
	size_b = list_size(list_b);
	moves_a = get_moves_to_top(index, size_a);
	moves_b = find_best_position_in_b(list_b, node->value, size_b, &best_index);
	return (moves_a + moves_b);
}

t_dnode	*find_best_node_to_push(t_dnode *list_a, t_dnode *list_b)
{
	t_dnode	*best_node;
	int		min_moves;
	t_dnode	*current;
	int		index;
	int		total_moves;

	best_node = NULL;
	min_moves = 999999;
	current = list_a;
	index = 0;
	while (current)
	{
		total_moves = get_total_moves(list_a, list_b, current, index);
		if (total_moves < min_moves)
		{
			min_moves = total_moves;
			best_node = current;
		}
		current = current->next;
		index++;
	}
	return (best_node);
}
