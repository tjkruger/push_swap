/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:00:05 by tjkruger          #+#    #+#             */
/*   Updated: 2025/03/03 13:38:19 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/list.h"
#include "../includes/utils.h"

void	ra(t_dnode **list_a)
{
	t_dnode	*temp;
	t_dnode	*last;

	if (!list_a || !(*list_a) || !(*list_a)->next)
		return ;
	temp = *list_a;
	*list_a = (*list_a)->next;
	last = *list_a;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	update_indexes(*list_a);
	ft_printf("ra\n");
}

void	rb(t_dnode **list_b)
{
	t_dnode	*temp;
	t_dnode	*last;

	if (!list_b || !(*list_b) || !(*list_b)->next)
		return ;
	temp = *list_b;
	*list_b = (*list_b)->next;
	last = *list_b;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	update_indexes(*list_b);
	ft_printf("rb\n");
}

void	rr(t_dnode **list_a, t_dnode **list_b)
{
	ra(list_a);
	rb(list_b);
	ft_printf("rr\n");
}
