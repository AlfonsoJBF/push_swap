/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 10:19:42 by mtapiado          #+#    #+#             */
/*   Updated: 2026/06/30 16:55:20 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

# include "stack.h"

// UTILS
t_node	*find_min(t_stack *stack);
t_node	*find_max(t_stack *stack);
void	move_min_to_top_a(t_program *p);
void	move_min_to_top_b(t_program *p);
void	move_max_to_top_a(t_program *p);
void	move_max_to_top_b(t_program *p);
int		get_node_position(t_stack *stack, t_node *node);
int		calculate_index(int *nums, t_stack *s);

// simple sort
void	sort_two(t_program *p);
void	sort_three(t_program *p);
void	sort_four(t_program *p);
void	sort_five(t_program *p);

// algorithms
void	selection_sort(t_program *p);
void	k_sort(t_program *p);
void	chunk_sort(t_program *p);

#endif