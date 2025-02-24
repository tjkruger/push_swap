/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:37:36 by tjkruger          #+#    #+#             */
/*   Updated: 2025/02/24 17:30:52 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/list.h"
#include "../includes/utils.h"

void	sort_for_three(t_dnode **list_a)
{
	if (!list_a || !(*list_a) || !(*list_a)->next || !(*list_a)->next->next)
		return ;
	if ((*list_a)->value > (*list_a)->next->value)
		sa(list_a);
	if ((*list_a)->next->value > (*list_a)->next->next->value)
		rra(list_a);
	if ((*list_a)->value > (*list_a)->next->value)
		sa(list_a);
}

int	get_moves_to_top(t_dnode *stack, int index, int size)
{
	if (index <= size / 2)
		return (index); // Use ra
	else
		return (size - index); // Use rra
}

t_dnode	*find_best_node_to_push(t_dnode *stack_a, t_dnode *stack_b)
{
	t_dnode	*best_node;
	int		min_moves;
	t_dnode	*current;
	int		index;
	int		size_a;
	int		size_b;

	best_node = NULL;
	min_moves = 999999;
	int moves_a, moves_b, total_moves;
	current = stack_a;
	index = 0;
	size_a = stack_size(stack_a);
	size_b = stack_size(stack_b);
	while (current)
	{
		moves_a = get_moves_to_top(stack_a, index, size_a);
		moves_b = get_moves_to_correct_position(stack_b, current->value,
				size_b);
		total_moves = moves_a + moves_b;
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

void	move_best_node(t_dnode **list_a, t_dnode **list_b)
{
	t_dnode	*best_node;
	int		moves_a;
	int		moves_b;

	best_node = find_best_node_to_push(*list_a, *list_b);
	if (!best_node)
		return ;
	moves_a = get_moves_to_top(*list_a, best_node->index, stack_size(*list_a));
	moves_b = get_moves_to_correct_position(*list_b, best_node->value,
			stack_size(*list_b));
	while (moves_a-- > 0)
		ra(list_a); // Rotate A
	while (moves_a++ < 0)
		rra(list_a); // Reverse rotate A
	while (moves_b-- > 0)
		rb(list_b); // Rotate B
	while (moves_b++ < 0)
		rrb(list_b);    // Reverse rotate B
	pb(list_a, list_b); // Push to B
}

void	get_sorted(t_dnode **list_a, t_dnode **list_b)
{
	move_best_node(list_a, list_b);
}

void	is_sorted(t_dnode **list_a, t_dnode **list_b)
{
	t_dnode	*node;
	int		counter;
	int		state;

	state = 0;
	counter = 0;
	node = *list_a;
	while (node->next)
	{
		if (node->value > node->next->value)
			state++;
		counter++;
	}
	if (state == 0) // is in order so just print out list
		print_list(*list_a, *list_b);
	else if (counter > 3 && state > 0) // big work needed bc more 3 unsorted
	{
		pb(list_a, list_b);
		pb(list_a, list_b);
		get_sorted(list_a, list_b);
	}
	else if (counter <= 3 && state > 0) // small work bc less then 3 unsorted
		sort_for_three(list_a);
}
