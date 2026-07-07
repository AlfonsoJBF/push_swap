/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:16:34 by albustos          #+#    #+#             */
/*   Updated: 2026/07/04 23:17:42 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libraries.h"

static void	metrics_init(t_metrics *b)
{
	b->pa = 0;
	b->pb = 0;
	b->sa = 0;
	b->sb = 0;
	b->ss = 0;
	b->ra = 0;
	b->rb = 0;
	b->rr = 0;
	b->rra = 0;
	b->rrb = 0;
	b->rrr = 0;
}

void	ft_bench_init(t_program *p)
{
	t_benchmark	*b;

	b = malloc(sizeof(t_benchmark));
	if (!b)
		return ;
	b->metrics = malloc(sizeof(t_metrics));
	if (!b->metrics)
		return ;
	metrics_init(b->metrics);
	b->total_ops = 0;
	b->disorder = 0;
	b->strategy = NULL;
	p->bench = b;
}
