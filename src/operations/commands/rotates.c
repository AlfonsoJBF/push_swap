/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:19:49 by albustos          #+#    #+#             */
/*   Updated: 2026/06/27 17:20:30 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/stack.h"
#include "../../../include/operations.h"
#include "../../../include/libraries.h"

void	ra(t_stack *stack)
{
	ft_rotate(stack);
	write(1, "sa\n", 3);
}

void	rb(t_stack *stack)
{
	ft_rotate(stack);
	write(1, "sb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "ss\n", 3);
}
