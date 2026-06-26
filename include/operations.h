/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 19:49:20 by albustos          #+#    #+#             */
/*   Updated: 2026/06/25 19:49:20 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef OPERATIONS_H
# define OPERATIONS_H
// PRIMITIVES
void	ft_push(t_stack *from, t_stack *to);
void	ft_swap(t_stack *stack);
void	ft_rotate(t_stack *stack);
void	ft_reverse_rotate(t_stack *stack);

#endif