/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:20:51 by albustos          #+#    #+#             */
/*   Updated: 2026/07/05 18:34:06 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/stack.h"
#include "../../../include/operations.h"
#include "../../../include/libraries.h"

void	rra(t_program *p)
{
	ft_reverse_rotate(p->a);
	p->bench->total_ops++;
	p->bench->metrics->rra++;
	write(1, "rra\n", 4);
}

void	rrb(t_program *p)
{
	ft_reverse_rotate(p->b);
	p->bench->total_ops++;
	p->bench->metrics->rrb++;
	write(1, "rrb\n", 4);
}

void	rrr(t_program *p)
{
	ft_reverse_rotate(p->a);
	ft_reverse_rotate(p->b);
	p->bench->total_ops++;
	p->bench->metrics->rrr++;
	write(1, "rrr\n", 4);
}
