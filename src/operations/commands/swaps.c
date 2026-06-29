/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:28:42 by albustos          #+#    #+#             */
/*   Updated: 2026/06/29 17:45:12 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/stack.h"
#include "../../../include/operations.h"
#include "../../../include/libraries.h"

void	sa(t_program *p)
{
	ft_swap(p->a);
	p->bench->total_ops++;
	p->bench->metrics->sa++;
	write(1, "sa\n", 3);
}

void	sb(t_program *p)
{
	ft_swap(p->b);
	p->bench->total_ops++;
	p->bench->metrics->sb++;
	write(1, "sb\n", 3);
}

void	ss(t_program *p)
{
	ft_swap(p->a);
	ft_swap(p->b);
	p->bench->total_ops++;
	p->bench->metrics->ss++;
	write(1, "ss\n", 3);
}
