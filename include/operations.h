/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 19:49:20 by albustos          #+#    #+#             */
/*   Updated: 2026/06/27 17:27:04 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "stack.h"

// PRIMITIVES
void	ft_push(t_stack *from, t_stack *to);
void	ft_swap(t_stack *stack);
void	ft_rotate(t_stack *stack);
void	ft_reverse_rotate(t_stack *stack);

// COMMANDS
void	rra(t_program *p);
void	rrb(t_program *p);
void	rrr(t_program *p);
void	ra(t_program *p);
void	rb(t_program *p);
void	rr(t_program *p);
void	sa(t_program *p);
void	sb(t_program *p);
void	ss(t_program *p);
void	pa(t_program *p);
void	pb(t_program *p);

#endif
