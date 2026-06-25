/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pull.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 01:38:11 by albustos          #+#    #+#             */
/*   Updated: 2026/06/26 01:38:11 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stack.h"
#include "../../include/libraries.h"

t_node	*ft_stack_pull(t_stack *stack)
{
	t_node *current;
	t_node *tmp;
	 
	current = stack->top;
	if (current == NULL)
		return (NULL);
	while(current->next->next != NULL)
		current = current->next;
	tmp = current->next;
	current->next = NULL;
	stack->size--;
	return (tmp);
}