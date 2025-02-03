/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:34:32 by tjkruger          #+#    #+#             */
/*   Updated: 2025/02/03 15:31:45 by tjkruger         ###   ########.fr       */
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
	print_list(list_a, list_b);
	// sa(&list_a);
	pb(&list_a, &list_b);
	pb(&list_a, &list_b);
	pb(&list_a, &list_b);
	pb(&list_a, &list_b);
	ft_printf("\n all to b \n"); // muss noch raus is nur für lesbarkeit
	print_list(list_a, list_b);
	// pa(&list_a, &list_b);
	// pa(&list_a, &list_b);
	// ft_printf("\n half back to a \n");
	// muss noch raus is nur für lesbarkeit
	// print_list(list_a, list_b);
	// ss(&list_a, &list_b);
	ft_printf("\n"); // muss noch raus is nur für lesbarkeit
	print_list(list_a, list_b);
	sb(&list_b);
	ft_printf("\n"); // muss noch raus is nur für lesbarkeit
	print_list(list_a, list_b);
	free_list(&list_a);
	return (0);
}
