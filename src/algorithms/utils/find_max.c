/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 14:22:10 by albustos          #+#    #+#             */
/*   Updated: 2026/07/05 18:22:31 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/stack.h"
#include <limits.h>

t_node	*find_max(t_stack *stack)
{
	t_node	*current;
	t_node	*max_node;

	current = stack->top;
	max_node = current;
	while (current)
	{
		if (current->value > max_node->value)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}
