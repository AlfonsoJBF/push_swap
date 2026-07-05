/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptative.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 02:52:35 by albustos          #+#    #+#             */
/*   Updated: 2026/07/03 02:52:35 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/stack.h"
#include "../../../include/libraries.h"
#include "../../../include/algorithms.h"
#include "../../../include/operations.h"

static int	sort_by_size(t_program *p)
{
	if (p->bench->disorder == 0)
		return (0);
	if (p->a->size == 2)
	{
		sort_two(p);
		return (1);
	}
	if (p->a->size == 3)
	{
		sort_three(p);
		return (1);
	}
	if (p->a->size == 4)
	{
		sort_four(p);
		return (1);
	}
	if (p->a->size == 5)
	{
		sort_five(p);
		return (1);
	}
	return (0);
}

void	adaptative_sort(t_program *p)
{
	if (sort_by_size(p))
		return ;
	if (p->bench->disorder <= 0.2)
	{
		selection_sort(p);
		return ;
	}
	else if (p->bench->disorder <= 0.5)
	{
		chunk_sort(p);
		return ;
	}
	else
		k_sort(p);
}
