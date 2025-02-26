/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:03:17 by tjkruger          #+#    #+#             */
/*   Updated: 2025/02/26 16:30:26 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/list.h"
#include "../includes/utils.h"

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

int	get_moves_to_top(t_dnode *list, int index, int size)
{
	if (index <= size / 2)
		return (index);
	else
		return (size - index);
}

int	get_moves_to_correct_position(t_dnode *stack_b, int value, int size_b)
{
	t_dnode	*current;
	int		index;
	t_dnode	*best_fit;
	int		best_fit_index;

	current = stack_b;
	index = 0;
	best_fit = NULL;
	best_fit_index = -1;
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
		best_fit_index = 0;
	return (get_moves_to_top(stack_b, best_fit_index, size_b));
}

int	get_total_moves(t_dnode *list_a, t_dnode *list_b, t_dnode *node, int index)
{
	int	moves_a;
	int	moves_b;
	int	size_a;
	int	size_b;

	size_a = listsize(list_a);
	size_b = listsize(list_b);
	moves_a = get_moves_to_top(list_a, index, size_a);
	moves_b = get_moves_to_correct_position(list_b, node->value, size_b);
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
