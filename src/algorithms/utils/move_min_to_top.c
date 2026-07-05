/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_min_to_top.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 14:39:32 by albustos          #+#    #+#             */
/*   Updated: 2026/07/05 18:24:03 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/stack.h"
#include "../../../include/operations.h"
#include "../../../include/algorithms.h"

void	move_min_to_top_a(t_program *p)
{
	t_node	*min;
	int		pos;
	int		size;

	min = find_min(p->a);
	pos = get_node_position(p->a, min);
	size = p->a->size;
	if (pos <= size / 2)
	{
		while (p->a->top != min)
			ra(p);
	}
	else
	{
		while (p->a->top != min)
			rra(p);
	}
}

void	move_min_to_top_b(t_program *p)
{
	t_node	*min;
	int		pos;
	int		size;

	min = find_min(p->b);
	pos = get_node_position(p->b, min);
	size = p->b->size;
	if (pos <= size / 2)
	{
		while (p->b->top != min)
			rb(p);
	}
	else
	{
		while (p->b->top != min)
			rrb(p);
	}
}
