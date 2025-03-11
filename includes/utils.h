/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:56:08 by tjkruger          #+#    #+#             */
/*   Updated: 2025/03/11 11:57:41 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		main(int argc, char **argv);
int		ft_atoi(const char *s);
void	sort_for_three(t_dnode **list_a);
void	rotate_b_to_max(t_dnode **list_b);
void	sort_fatty(t_dnode **list_a, t_dnode **list_b);
void	is_sorted(t_dnode **list_a, t_dnode **list_b);
void	first_two(t_dnode **list_a, t_dnode **list_b);

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

int		get_moves_to_top(int index, int size);
int		calculate_moves(int index, int size);
int		find_best_position_in_b(t_dnode *stack_b, int value, int size_b,
			int *best_index);
int		get_total_moves(t_dnode *list_a, t_dnode *list_b, t_dnode *node,
			int index);
t_dnode	*find_best_node_to_push(t_dnode *list_a, t_dnode *list_b);

int		find_best_bigger_neighbour(t_dnode *stack_b, int value);
int		find_best_smaller_neighbour(t_dnode *stack_b, int value);
void	move_top_a(t_dnode **list_a, t_dnode **list_b);
void	move_cor_pos_b(t_dnode **list_a, t_dnode **list_b, t_dnode *best_node);

t_dnode	*get_node_at_index(t_dnode *node, int index);
int		list_size(t_dnode *list);

#endif