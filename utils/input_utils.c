/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:43:21 by tjkruger          #+#    #+#             */
/*   Updated: 2025/01/23 18:21:33 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/list.h"
#include "../includes/utils.h"
#include <stdlib.h>

int	ft_atoi(const char *s)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	sign = 1;
	result = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\v'
		|| s[i] == '\f' || s[i] == '\r')
		i++;
	if (s[i] == '+' || s[i] == '-')
		if (s[i++] == '-')
			sign = -1;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		result = result * 10 + (s[i++] - '0');
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
			return (0);
	}
	return ((int)(result * sign));
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
