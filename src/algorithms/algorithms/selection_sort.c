/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 14:59:12 by albustos          #+#    #+#             */
/*   Updated: 2026/06/29 15:04:15 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/stack.h"
#include "../../../include/operations.h"
#include "../../../include/algorithms.h"

void	selection_sort(t_program *p)
{
	while (p->a->size > 0)
	{
		move_min_to_top_a(p);
		pb(p);
	}
	while(p->b->size > 0)
		pa(p);
}