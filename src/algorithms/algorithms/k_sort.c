/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 00:27:53 by albustos          #+#    #+#             */
/*   Updated: 2026/06/30 00:27:53 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/stack.h"
#include "../../../include/libraries.h"
#include "../../../include/algorithms.h"
#include "../../../include/operations.h"

static int	my_sqrt(int n)
{
	int	x;
	int	y;

	x = n;
	y = 1;
	while (x > y)
	{
		x = (x + y) / 2;
		y = n / x;
	}
	return (x);
}

static void	return_to_a(t_program *p)
{
	move_max_to_top_b(p);
	pa(p);
}

void	k_sort(t_program *p)
{
	int		k;
	t_node	*top;
	int		processed;

	k = 1.3 * my_sqrt(p->a->size);
	processed = 0;
	while (p->a->size > 0)
	{
		top = p->a->top;
		if (top->index <= processed)
		{
			pb(p);
			rb(p);
			processed++;
		}
		else if (top->index <= processed + k)
		{
			pb(p);
			processed++;
		}
		else
			ra(p);
	}
	while (p->b->size > 0)
		return_to_a(p);
}
