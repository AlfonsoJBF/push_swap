/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 14:21:27 by albustos          #+#    #+#             */
/*   Updated: 2026/06/29 12:09:16 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/algorithms.h"
#include "../../include/operations.h"

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

static int	find_min_pos(t_stack *stack)
{
	t_node	*current;
	int		min;
	int		pos;
	int		min_pos;

	current = stack->top;
	min = current->value;
	pos = 0;
	min_pos = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

static void	move_min_to_top(t_program *p)
{
	int	min_pos;

	min_pos = find_min_pos(p->a);
	if (min_pos <= p->a->size / 2)
	{
		while (min_pos > 0)
		{
			ra(p);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < p->a->size)
		{
			rra(p);
			min_pos++;
		}
	}
}

void	sort_four(t_program *p)
{
	if (!p || !p->a || !p->b || p->a->size != 4)
		return ;
	if (!p->a->top || !p->a->top->next)
		return ;
	if (!p->a->top->next->next || !p->a->top->next->next->next)
		return ;
	move_min_to_top(p);
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
	move_min_to_top(p);
	pb(p);
	move_min_to_top(p);
	pb(p);
	sort_three(p);
	pa(p);
	pa(p);
}
