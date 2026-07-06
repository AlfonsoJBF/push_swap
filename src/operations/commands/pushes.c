/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:13:02 by albustos          #+#    #+#             */
/*   Updated: 2026/07/06 13:21:01 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/stack.h"
#include "../../../include/operations.h"
#include "../../../include/libraries.h"

void	pb(t_program *p)
{
	ft_push(p->a, p->b);
	if (p->bench)
	{
		p->bench->total_ops++;
		p->bench->metrics->pb++;
	}
	if (p->print_ops)
		write(1, "pb\n", 3);
}

void	pa(t_program *p)
{
	ft_push(p->b, p->a);
	if (p->bench)
	{
		p->bench->total_ops++;
		p->bench->metrics->pa++;
	}
	if (p->print_ops)
		write(1, "pa\n", 3);
}
