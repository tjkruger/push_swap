/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:00:57 by tjkruger          #+#    #+#             */
/*   Updated: 2025/01/24 17:59:34 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/list.h"
#include "../includes/utils.h"

void	sa(t_dnode **list_a)
{
	int	temp;

	if (!list_a || !(*list_a) || !(*list_a)->next)
		return ;
	temp = (*list_a)->value;
	(*list_a)->value = (*list_a)->prev->value;
	(*list_a)->prev->value = temp;
}

void	sb(t_dnode **list_b)
{
	int	temp;

	if (!list_b || !(*list_b) || !(*list_b)->next)
		return ;
	temp = (*list_b)->value;
	(*list_b)->value = (*list_b)->prev->value;
	(*list_b)->prev->value = temp;
}

void	ss(t_dnode **list_a, t_dnode **list_b)
{
	sa(list_a);
	sb(list_b);
}
