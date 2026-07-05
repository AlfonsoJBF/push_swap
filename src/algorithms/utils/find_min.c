/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 14:22:10 by albustos          #+#    #+#             */
/*   Updated: 2026/07/05 18:20:22 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/stack.h"
#include <limits.h>

t_node	*find_min(t_stack *stack)
{
	t_node	*current;
	t_node	*min_node;

	current = stack->top;
	min_node = current;
	while (current)
	{
		if (current->value < min_node->value)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}
