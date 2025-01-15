/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:01:56 by tjkruger          #+#    #+#             */
/*   Updated: 2024/11/08 12:38:58 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int *chars_pr)
{
	if (*chars_pr == -1)
		return (-1);
	if (n == -2147483648)
	{
		ft_putchar('-', chars_pr);
		ft_putstr("2147483648", chars_pr);
		return (11);
	}
	if (n < 0)
	{
		ft_putchar('-', chars_pr);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10, chars_pr);
	return (ft_putchar((n % 10) + '0', chars_pr));
}
