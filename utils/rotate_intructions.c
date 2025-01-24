/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_intructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:00:05 by tjkruger          #+#    #+#             */
/*   Updated: 2025/01/24 19:43:11 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/list.h"
#include "../includes/utils.h"

void	ra(t_dnode **list_a)
{
	t_dnode	*temp;
	t_dnode	*last;

	temp = *list_a;
	*list_a = (*list_a)->next;
	last = *list_a;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
}

void	rb(t_dnode **list_b)
{
	t_dnode	*temp;
	t_dnode	*last;

	temp = *list_b;
	*list_b = (*list_b)->next;
	last = *list_b;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
}

void	rr(t_dnode **list_a, t_dnode **list_b)
{
	ra(list_a);
	rb(list_b);
}

void	rra(t_dnode **list_a)
{
	t_dnode	*secondlast;
	t_dnode	*last;

	last = *list_a;
	while (last->next)
		last = last->next;
	secondlast = last->prev;
	secondlast->prev = NULL;
	last->next = *list_a;
	(*list_a)->prev = last;
	last->prev = NULL;
	*list_a = last;
}

void	rrb(t_dnode **list_b)
{
	t_dnode	*secondlast;
	t_dnode	*last;

	last = *list_b;
	while (last->next)
		last = last->next;
	secondlast = last->prev;
	secondlast->prev = NULL;
	last->next = *list_b;
	(*list_b)->prev = last;
	last->prev = NULL;
	*list_b = last;
}
