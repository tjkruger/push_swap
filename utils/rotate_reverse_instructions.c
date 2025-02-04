/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse_instructions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:37:17 by tjkruger          #+#    #+#             */
/*   Updated: 2025/02/04 15:37:47 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/list.h"
#include "../includes/utils.h"

void	rra(t_dnode **list_a)
{
	t_dnode	*secondlast;
	t_dnode	*last;

	if (!list_a || !(*list_a) || !(*list_a)->next)
		return ;
	last = *list_a;
	while (last->next)
		last = last->next;
	secondlast = last->prev;
	secondlast->next = NULL;
	last->next = *list_a;
	(*list_a)->prev = last;
	last->prev = NULL;
	*list_a = last;
}

void	rrb(t_dnode **list_b)
{
	t_dnode	*secondlast;
	t_dnode	*last;

	if (!list_b || !(*list_b) || !(*list_b)->next)
		return ;
	last = *list_b;
	while (last->next)
		last = last->next;
	secondlast = last->prev;
	secondlast->next = NULL;
	last->next = *list_b;
	(*list_b)->prev = last;
	last->prev = NULL;
	*list_b = last;
}

void	rrr(t_dnode **list_a, t_dnode **list_b)
{
	rra(list_a);
	rrb(list_b);
}
