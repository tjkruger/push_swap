/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:37:36 by tjkruger          #+#    #+#             */
/*   Updated: 2025/03/10 15:01:32 by tjkruger         ###   ########.fr       */
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

void	sort_fatty(t_dnode **list_a, t_dnode **list_b)
{
	while (*list_a)
	{
		move_top_a(list_a, list_b);
		move_cor_pos_b(list_a, list_b, get_node_at_index(*list_a, 0));
	}
	rotate_b_to_max(list_b);
	while (*list_b)
		pa(list_a, list_b);
}

void	rotate_b_to_max(t_dnode **list_b)
{
	t_dnode	*maxnode;
	t_dnode	*node;
	int		max_index;
	int		current_index;

	max_index = 0;
	current_index = 0;
	if (!list_b || !(*list_b)) // Fix: Handle empty list case
		return ;
	maxnode = *list_b;
	node = *list_b;
	while (node) // Find the max value node and its index
	{
		if (node->value > maxnode->value)
		{
			maxnode = node;
			max_index = current_index;
		}
		node = node->next;
		current_index++;
	}
	while (*list_b != maxnode)
	{
		print_list(*list_b, NULL); // Debugging: Check if list is changing
		if (max_index < list_size(*list_b) / 2)
			rb(list_b);
		else
			rrb(list_b);
	}
}

void	is_sorted(t_dnode **list_a, t_dnode **list_b)
{
	t_dnode	*node;
	int		state;

	state = 0;
	node = *list_a;
	while (node->next)
	{
		if (node->value > node->next->value)
			state++;
		node = node->next;
	}
	if (state == 0) // is in order so just print out list
		print_list(*list_a, *list_b);
	else if (list_size(*list_a) <= 3) // small work bc less then 3 unsorted
		sort_for_three(list_a);
	else // big work needed bc more 3 unsorted
	{
		sort_fatty(list_a, list_b);
	}
}

void	first_two(t_dnode **list_a, t_dnode **list_b)
{
	pb(list_a, list_b);
	pb(list_a, list_b);
	if (get_node_at_index(*list_b, 0)->value > get_node_at_index(*list_b,
			1)->value)
		rb(list_b);
}