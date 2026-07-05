/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 21:04:03 by albustos          #+#    #+#             */
/*   Updated: 2026/07/04 21:04:03 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/stack.h"

int	compute_disorder(t_stack *a)
{
	t_node	*current;
	int		i;
	int		mistakes;

	if (a->size == 1)
		return (0);
	i = 0;
	mistakes = 0;
	current = a->top;
	while (i < (int)(a->size / 2))
	{
		if (current->value > current->next->value)
			mistakes++;
		current = current->next->next;
		i++;
	}
	return (((float) mistakes / (a->size / 2)) * 10000);
}
