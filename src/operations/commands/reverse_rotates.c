/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:20:51 by albustos          #+#    #+#             */
/*   Updated: 2026/06/27 17:22:21 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/stack.h"
#include "../../../include/operations.h"
#include "../../../include/libraries.h"

void	rra(t_stack *stack)
{
	ft_reverse_rotate(stack);
	write(1, "sa\n", 3);
}

void	rrb(t_stack *stack)
{
	ft_reverse_rotate(stack);
	write(1, "sb\n", 3);
}

void	rrr(t_stack *a, t_stack *b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	write(1, "ss\n", 3);
}

