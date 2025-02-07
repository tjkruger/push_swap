/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:34:32 by tjkruger          #+#    #+#             */
/*   Updated: 2025/02/07 18:44:00 by tjkruger         ###   ########.fr       */
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
	// pb(&list_a, &list_b);
	// pb(&list_a, &list_b);
	// pb(&list_a, &list_b);
	// ft_printf("okay pb worked \n\n");
	// print_list(list_a, list_b);
	// sa(&list_a);
	// sb(&list_b);
	// ft_printf("okay sb and sa worked \n\n");
	// print_list(list_a, list_b);
	// ra(&list_a);
	// rb(&list_b);
	// ft_printf("okay ra and rb worked \n\n");
	// print_list(list_a, list_b);
	// rra(&list_a);
	// rrb(&list_b);
	// ft_printf("okay rra and rrb worked \n\n");
	// print_list(list_a, list_b);
	push_to_b(&list_a, &list_b);
	print_list(list_a, list_b);
	free_list(&list_a);
	free_list(&list_b);
	return (0);
}
