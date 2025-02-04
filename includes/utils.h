/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:56:08 by tjkruger          #+#    #+#             */
/*   Updated: 2025/02/04 16:04:26 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		main(int argc, char **argv);
int		ft_atoi(const char *s);
void	push_to_b(t_dnode **list_a, t_dnode **list_b);
t_dnode	*find_largest(t_dnode *list);
t_dnode	*find_smallest(t_dnode *list);
void	ra(t_dnode **list_a);
void	rb(t_dnode **list_b);
void	rr(t_dnode **list_a, t_dnode **list_b);
void	rra(t_dnode **list_a);
void	rrb(t_dnode **list_b);
void	rrr(t_dnode **list_a, t_dnode **list_b);
void	sa(t_dnode **list_a);
void	sb(t_dnode **list_b);
void	ss(t_dnode **list_a, t_dnode **list_b);
void	pa(t_dnode **list_a, t_dnode **list_b);
void	pb(t_dnode **list_a, t_dnode **list_b);

#endif