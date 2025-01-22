/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:06:26 by tjkruger          #+#    #+#             */
/*   Updated: 2025/01/21 14:37:49 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putptr(unsigned long ptr, int *chars_pr)
{
	if (ft_putstr("0x", chars_pr) == -1)
		return (-1);
	return (ft_puthex(ptr, 0, chars_pr));
}
