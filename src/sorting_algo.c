/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:37:36 by tjkruger          #+#    #+#             */
/*   Updated: 2025/02/07 19:21:35 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/list.h"
#include "../includes/utils.h"

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
		print_list(list_a, list_b);
	else if (counter > 3 && state > 0)
		// big work needed bc more then 3 unsorted
		get_sorted(list_a, list_b);
	else if (counter <= 3 && state > 0) // small work bc less then 3 unsorted
		get_sorted_for_three(list_a, list_b);
}
