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

/* int	compute_disorder(t_stack *a)
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
} */

int	compute_disorder(t_stack *a)
{
	t_node	*first;
	t_node	*second;
	int		mistakes;
	int		total_pairs;

	first = a->top;
	mistakes = 0;
	total_pairs = 0;
	while (first)
	{
		second = first->next;
		while (second)
		{
			total_pairs++;
			if (first->value > second->value)
				mistakes++;
			second = second->next;
		}
		first = first->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return (((double)mistakes / (double)total_pairs) * 10000);
}
