/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_delete_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 14:14:14 by albustos          #+#    #+#             */
/*   Updated: 2026/06/25 14:14:14 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stack.h"
#include "../../include/libraries.h"

void	ft_stack_delete_node(t_stack *stack, t_node *node)
{
	if (stack == NULL || node == NULL)
		return ;
	if (stack->top == node)
	{
		stack->top = node->next;
	}
	else
	{
		t_node *current = stack->top;
		while (current != NULL && current->next != node)
		{
			current = current->next;
		}
		if (current != NULL)
			current->next = node->next;
	}
	free(node);
	stack->size--;
}