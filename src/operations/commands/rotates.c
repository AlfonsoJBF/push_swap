/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:19:49 by albustos          #+#    #+#             */
/*   Updated: 2026/06/29 17:46:39 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/stack.h"
#include "../../../include/operations.h"
#include "../../../include/libraries.h"

void	ra(t_program *p)
{
	ft_rotate(p->a);
	p->bench->total_ops++;
	p->bench->metrics->ra++;
	write(1, "ra\n", 3);
}

void	rb(t_program *p)
{
	ft_rotate(p->b);
	p->bench->total_ops++;
	p->bench->metrics->rb++;
	write(1, "rb\n", 3);
}

void	rr(t_program *p)
{
	ft_rotate(p->a);
	ft_rotate(p->b);
	p->bench->total_ops++;
	p->bench->metrics->rr++;
	write(1, "rr\n", 3);
}
