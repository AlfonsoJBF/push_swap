/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:19:49 by albustos          #+#    #+#             */
/*   Updated: 2026/07/06 11:52:30 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/stack.h"
#include "../../../include/operations.h"
#include "../../../include/libraries.h"

void	ra(t_program *p)
{
	ft_rotate(p->a);
	if (p->bench)
	{
		p->bench->total_ops++;
		p->bench->metrics->ra++;
	}
	if (p->print_ops)
		write(1, "ra\n", 3);
}

void	rb(t_program *p)
{
	ft_rotate(p->b);
	if (p->bench)
	{
		p->bench->total_ops++;
		p->bench->metrics->rb++;
	}
	if (p->print_ops)
		write(1, "rb\n", 3);
}

void	rr(t_program *p)
{
	ft_rotate(p->a);
	ft_rotate(p->b);
	if (p->bench)
	{
		p->bench->total_ops++;
		p->bench->metrics->rr++;
	}
	if (p->print_ops)
		write(1, "rr\n", 3);
}
