/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:19:17 by tjkruger          #+#    #+#             */
/*   Updated: 2025/01/21 14:02:28 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_dnode
{
	int				value;
	struct s_dnode	*prev;
	struct s_dnode	*next;
}					t_dnode;

t_dnode				*create_node(int value);
void				add_to_list_back(t_dnode **list, t_dnode *new_node);
void				print_list(t_dnode *list);
void				free_list(t_dnode **list);
t_dnode				*parse_input(int argc, char **argv);

#endif
