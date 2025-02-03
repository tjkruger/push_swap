/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:00:57 by tjkruger          #+#    #+#             */
/*   Updated: 2025/02/03 15:32:08 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/list.h"
#include "../includes/utils.h"

void	sa(t_dnode **list_a)
{
	t_dnode	*first;
	t_dnode	*second;

	if (!list_a || !(*list_a) || !(*list_a)->next)
		return ;
	first = *list_a;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	*list_a = second;
	first->prev = second;
}

void	sb(t_dnode **list_b)
{
	t_dnode	*first;
	t_dnode	*second;

	if (!list_b || !(*list_b) || !(*list_b)->next)
		return ;
	first = *list_b;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	*list_b = second;
	first->prev = second;
}

void	ss(t_dnode **list_a, t_dnode **list_b)
{
	sa(list_a);
	sb(list_b);
}
