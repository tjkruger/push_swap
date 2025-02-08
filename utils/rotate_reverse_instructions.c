/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse_instructions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:37:17 by tjkruger          #+#    #+#             */
/*   Updated: 2025/02/08 15:56:49 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/list.h"
#include "../includes/utils.h"

void	rra(t_dnode **list_a)
{
	t_dnode	*last;
	t_dnode	*secondlast;

	if (!list_a || !(*list_a) || !(*list_a)->next)
		return ;
	last = *list_a;
	secondlast = *list_a;
	while (last->next)
		last = last->next;
	while (secondlast->next->next)
		secondlast = secondlast->next;
	last->next = *list_a;
	*list_a = last;
	secondlast->next = NULL;
	ft_printf("rra\n");
}

void	rrb(t_dnode **list_b)
{
	t_dnode	*last;
	t_dnode	*secondlast;

	if (!list_b || !(*list_b) || !(*list_b)->next)
		return ;
	last = *list_b;
	secondlast = *list_b;
	while (last->next)
		last = last->next;
	while (secondlast->next->next)
		secondlast = secondlast->next;
	last->next = *list_b;
	*list_b = last;
	secondlast->next = NULL;
	ft_printf("rrb\n");
}

void	rrr(t_dnode **list_a, t_dnode **list_b)
{
	rra(list_a);
	rrb(list_b);
	ft_printf("rrr\n");
}
