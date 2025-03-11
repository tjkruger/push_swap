/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:01:58 by tjkruger          #+#    #+#             */
/*   Updated: 2025/03/03 13:39:30 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/list.h"
#include "../includes/utils.h"

void	pa(t_dnode **list_a, t_dnode **list_b)
{
	t_dnode	*temp;

	if (!list_b || !(*list_b))
		return ;
	temp = *list_b;
	*list_b = (*list_b)->next;
	temp->next = *list_a;
	*list_a = temp;
	update_indexes(*list_a);
	ft_printf("pa\n");
}

void	pb(t_dnode **list_a, t_dnode **list_b)
{
	t_dnode	*temp;

	if (!list_a || !(*list_a))
		return ;
	temp = *list_a;
	*list_a = (*list_a)->next;
	temp->next = *list_b;
	*list_b = temp;
	update_indexes(*list_b);
	ft_printf("pb\n");
}
