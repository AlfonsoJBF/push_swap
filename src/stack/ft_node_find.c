/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 00:45:35 by albustos          #+#    #+#             */
/*   Updated: 2026/06/30 00:45:35 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stack.h"
#include "../../include/libraries.h"

t_node	*ft_node_find(t_stack *s, int value)
{
	t_node	*current;

	if (!s)
		return (NULL);
	current = s->top;
	while (current)
	{
		if (current->value == value)
			return (current);
		current = current->next;
	}
	return (NULL);
}
