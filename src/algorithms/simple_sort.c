/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 14:21:27 by albustos          #+#    #+#             */
/*   Updated: 2026/07/05 18:14:36 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/algorithms.h"
#include "../../include/operations.h"
#include "../../include/libraries.h"
#include "../../include/stack.h"

void	sort_two(t_program *p)
{
	if (!p || !p->a || p->a->size != 2)
		return ;
	if (!p->a->top || !p->a->top->next)
		return ;
	if (p->a->top->value > p->a->top->next->value)
		sa(p);
}

void	sort_three(t_program *p)
{
	int	a;
	int	b;
	int	c;

	if (!p || !p->a || p->a->size != 3)
		return ;
	if (!p->a->top || !p->a->top->next || !p->a->top->next->next)
		return ;
	a = p->a->top->value;
	b = p->a->top->next->value;
	c = p->a->top->next->next->value;
	if (a > b && a > c)
		ra(p);
	else if (b > a && b > c)
		rra(p);
	if (p->a->top->value > p->a->top->next->value)
		sa(p);
}

void	sort_four(t_program *p)
{
	if (!p || !p->a || !p->b || p->a->size != 4)
		return ;
	if (!p->a->top || !p->a->top->next)
		return ;
	if (!p->a->top->next->next || !p->a->top->next->next->next)
		return ;
	move_min_to_top_a(p);
	pb(p);
	sort_three(p);
	pa(p);
}

void	sort_five(t_program *p)
{
	if (!p || !p->a || !p->b || p->a->size != 5)
		return ;
	if (!p->a->top || !p->a->top->next)
		return ;
	if (!p->a->top->next->next || !p->a->top->next->next->next)
		return ;
	if (!p->a->top->next->next->next->next)
		return ;
	move_min_to_top_a(p);
	pb(p);
	move_min_to_top_a(p);
	pb(p);
	sort_three(p);
	pa(p);
	pa(p);
}
