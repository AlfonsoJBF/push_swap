/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 14:53:58 by albustos          #+#    #+#             */
/*   Updated: 2026/07/05 18:22:53 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/stack.h"

int	get_node_position(t_stack *stack, t_node *node)
{
	t_node	*current;
	int		i;

	current = stack->top;
	i = 0;
	while (current)
	{
		if (current == node)
			return (i);
		current = current->next;
		i++;
	}
	return (-1);
}
