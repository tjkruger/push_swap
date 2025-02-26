/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:37:36 by tjkruger          #+#    #+#             */
/*   Updated: 2025/02/26 16:01:08 by tjkruger         ###   ########.fr       */
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
