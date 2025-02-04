/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:34:32 by tjkruger          #+#    #+#             */
/*   Updated: 2025/02/04 16:20:28 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/list.h"
#include "../includes/utils.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_dnode	*list_a;
	t_dnode	*list_b;

	list_a = parse_input(argc, argv);
	list_b = NULL;
	if (list_a == NULL)
	{
		return (1);
	}
	ft_printf("Init a and b\n");
	print_list(list_a, list_b);
	ft_printf("\noutput after fckn actual sorting\n");
	print_list(list_a, list_b);
	free_list(&list_a);
	free_list(&list_b);
	return (0);
}
