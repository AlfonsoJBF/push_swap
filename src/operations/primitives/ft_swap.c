/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 22:22:52 by albustos          #+#    #+#             */
/*   Updated: 2026/06/25 22:22:52 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/stack.h"
#include "../../../include/libraries.h"

void	ft_swap(t_stack *stack)
{
	t_node *tmp;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	tmp = ft_stack_pop(stack);
	tmp->next = stack->top->next;
	stack->top->next = tmp;
	stack->size++;
}