/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_addfront.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 23:07:25 by albustos          #+#    #+#             */
/*   Updated: 2026/06/26 00:52:04 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stack.h"
#include "../../include/libraries.h"

void ft_stack_addfront(t_stack *stack, t_node *node)
{
	if (node == NULL)
		return ;
	if (stack->top == NULL)
	{
		stack->top = node;
		stack->size++;
		return ;
	}
	node->next = stack->top;
	stack->top = node;
	stack->size++;
}
