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

void	adaptative_sort(t_program *p)
{
	if (p->a->size == 2)
	{
		sort_two(p);
		return ;
	}
	if (p->a->size == 3)
	{
		sort_three(p);
		return ;
	}
	if (p->a->size == 4)
	{
		sort_four(p);
		return ;
	}
	if (p->a->size == 5)
	{
		sort_five(p);
		return ;
	}
	else if (p->a->size <= 100)
	{
		chunk_sort(p);
		return ;
	}
	else
		k_sort(p);
}