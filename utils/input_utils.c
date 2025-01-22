/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:43:21 by tjkruger          #+#    #+#             */
/*   Updated: 2025/01/21 16:11:57 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/list.h"
#include "../includes/utils.h"
#include <stdlib.h>

int	ft_atoi(const char *s)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\v'
		|| s[i] == '\f' || s[i] == '\r')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	result = result * sign;
	if (result > 2147483647 || result < -2147483648)
		return (0);
	return ((int)result);
}

int	is_int(int value)
{
	if (value > 2147483647 || value < -2147483648)
		return (0);
	return (1);
}

int	is_valid_input(const char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\v'
		|| s[i] == '\f' || s[i] == '\r')
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

t_dnode	*parse_input(int argc, char **argv)
{
	t_dnode	*list;
	int		value;
	int		i;

	list = NULL;
	i = 1;
	while (i < argc)
	{
		if (!is_valid_input(argv[i]))
		{
			ft_printf("Error: Invalid input '%s'\n", argv[i]);
			free_list(&list);
			return (NULL);
		}
		value = ft_atoi(argv[i]);
		if (value == 0 && argv[i][0] != '0')
		{
			ft_printf("Error: Invalid input '%s'\n", argv[i]);
			free_list(&list);
			return (NULL);
		}
		add_to_list_back(&list, create_node(value));
		i++;
	}
	return (list);
}
