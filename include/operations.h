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

#include "stack.h"

// PRIMITIVES
void	ft_push(t_stack *from, t_stack *to);
void	ft_swap(t_stack *stack);
void	ft_rotate(t_stack *stack);
void	ft_reverse_rotate(t_stack *stack);

// COMMANDS
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *a, t_stack *b);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *a, t_stack *b);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack, t_stack *b);
void	pa(t_stack *from, t_stack *to);
void	pb(t_stack *from, t_stack *to);


#endif
