/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_max_to_top.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 14:39:32 by albustos          #+#    #+#             */
/*   Updated: 2026/06/30 02:22:03 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/stack.h"
#include "../../../include/operations.h"
#include "../../../include/algorithms.h"

void	move_max_to_top_a(t_program *p)
{
	t_node	*max;
	int		pos;
	int		size;

	max = find_max(p->a);
	pos = get_node_position(p->a, max);
	size = p->a->size;

	if (pos <= size / 2)
	{
		while (p->a->top != max)
			ra(p);
	}
	else
	{
		while (p->a->top != max)
			rra(p);
	}
}

void	move_max_to_top_b(t_program *p)
{
	t_node	*max;
	int		pos;
	int		size;

	max = find_max(p->b);
	pos = get_node_position(p->b, max);
	size = p->b->size;

	if (pos <= size / 2)
	{
		while (p->b->top != max)
			rb(p);
	}
	else
	{
		while (p->b->top != max)
			rrb(p);
	}
}