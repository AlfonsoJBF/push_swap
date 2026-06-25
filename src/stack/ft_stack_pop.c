/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 19:08:47 by albustos          #+#    #+#             */
/*   Updated: 2026/06/25 19:08:47 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stack.h"
#include "../../include/libraries.h"

t_node	*ft_stack_pop(t_stack *stack)
{
	t_node *tmp;

	tmp = stack->top;
	if (tmp == NULL)
		return (NULL);
	stack->top = stack->top->next;
	stack->size--;
	return (tmp);
}