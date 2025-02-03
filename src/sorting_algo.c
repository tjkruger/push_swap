/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:37:36 by tjkruger          #+#    #+#             */
/*   Updated: 2025/02/03 19:20:39 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/list.h"
#include "../includes/utils.h"
#include <stdio.h>

void	splitting_stack_to_a(t_dnode **list_a, t_dnode **list_b)
{
	t_dnode	*counter;
	int		count;

	count = 0;
	counter = *list_b;
	while (counter)
	{
		counter = counter->next;
		count++;
	}
	count = count / 2;
	while (count)
	{
		pa(list_a, list_b);
		count--;
	}
}

void	splitting_stack_to_b(t_dnode **list_a, t_dnode **list_b)
{
	t_dnode	*counter;
	int		count;

	count = 0;
	counter = *list_a;
	while (counter)
	{
		counter = counter->next;
		count++;
	}
	count = count / 2;
	while (count)
	{
		pb(list_a, list_b);
		count--;
	}
}

void	sort_a(t_dnode **list_a, t_dnode **list_b)
{
	t_dnode	*biggest_node;
	t_dnode	*node;

	if (*list_a == NULL)
		return ;
	node = *list_a;
	biggest_node = node;
	while (*list_a != NULL)
	{
		node = *list_a;
		biggest_node = node;
		while (node)
		{
			if (node->value < biggest_node->value)
				biggest_node = node;
			node = node->next;
		}
		while ((*list_a)->value != biggest_node->value)
			ra(list_a);
		pb(list_a, list_b);
	}
	splitting_stack_to_a(list_a, list_b);
}

void	sort_b_into_a(t_dnode **list_a, t_dnode **list_b)
{
}
