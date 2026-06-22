/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_addbck.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 01:08:34 by albustos          #+#    #+#             */
/*   Updated: 2026/06/21 02:25:09 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stack.h"
#include "../../include/libraries.h"

void ft_stack_addback(t_stack *stack, t_node *node)
{
	t_node *last;

	last = ft_stack_last(stack);
	if (last == NULL)
	{
		stack->top = node;
		return ;
	}
	last->next = node;
	stack->size += 1;
	
}
