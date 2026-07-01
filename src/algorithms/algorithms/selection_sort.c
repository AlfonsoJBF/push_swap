/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 14:59:12 by albustos          #+#    #+#             */
/*   Updated: 2026/07/01 18:46:29 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/stack.h"
#include "../../../include/operations.h"
#include "../../../include/algorithms.h"

// void	selection_sort(t_program *p)
// {
// 	while (p->a->size > 0)
// 	{
// 		move_min_to_top_a(p);
// 		pb(p);
// 	}
// 	while (p->b->size > 0)
// 		pa(p);
// }

static int	extreme_pos(t_stack *s, int max)
{
	t_node	*n;
	int		pos;
	int		best;
	int		best_pos;

	n = s->top;
	pos = 0;
	best = n->index;
	best_pos = 0;
	while (n)
	{
		if ((max && n->index > best) || (!max && n->index < best))
		{
			best = n->index;
			best_pos = pos;
		}
		n = n->next;
		pos++;
	}
	return (best_pos);
}

static int	cost_to_top(t_stack *s, int pos)
{
	if (pos <= s->size / 2)
		return (pos);
	return (s->size - pos);
}

static void	move_pos_top_a(t_program *p, int pos)
{
	int	size;

	size = p->a->size;
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(p);
	else
		while (pos++ < size)
			rra(p);
}

static void	move_pos_top_b(t_program *p, int pos)
{
	int	size;

	size = p->b->size;
	if (pos <= size / 2)
		while (pos-- > 0)
			rb(p);
	else
		while (pos++ < size)
			rrb(p);
}

void	selection_sort(t_program *p)
{
	int	min_pos;
	int	max_pos;

	while (p->a->size > 0)
	{
		min_pos = extreme_pos(p->a, 0);
		max_pos = extreme_pos(p->a, 1);
		if (cost_to_top(p->a, min_pos) <= cost_to_top(p->a, max_pos))
		{
			move_pos_top_a(p, min_pos);
			pb(p);
		}
		else
		{
			move_pos_top_a(p, max_pos);
			pb(p);
			if (p->b->size > 1)
				rb(p);
		}
	}
	move_pos_top_b(p, extreme_pos(p->b, 1));
	while (p->b->size > 0)
		pa(p);
}
