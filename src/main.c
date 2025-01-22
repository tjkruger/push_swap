/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:34:32 by tjkruger          #+#    #+#             */
/*   Updated: 2025/01/21 15:51:20 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/list.h"
#include "../includes/utils.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_dnode	*list;
	t_dnode	*temp;

	list = parse_input(argc, argv);
	if (list == NULL)
	{
		return (1);
	}
	temp = list;
	while (temp != NULL)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
	free_list(&list);
	return (0);
}
