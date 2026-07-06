/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:28:42 by albustos          #+#    #+#             */
/*   Updated: 2026/07/06 11:52:56 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/stack.h"
#include "../../../include/operations.h"
#include "../../../include/libraries.h"

void	sa(t_program *p)
{
	ft_swap(p->a);
	if (p->bench)
	{
		p->bench->total_ops++;
		p->bench->metrics->sa++;
	}
	if (p->print_ops)
		write(1, "sa\n", 3);
}

void	sb(t_program *p)
{
	ft_swap(p->b);
	if (p->bench)
	{
		p->bench->total_ops++;
		p->bench->metrics->sb++;
	}
	if (p->print_ops)
		write(1, "sb\n", 3);
}

void	ss(t_program *p)
{
	ft_swap(p->a);
	ft_swap(p->b);
	if (p->bench)
	{
		p->bench->total_ops++;
		p->bench->metrics->ss++;
	}
	if (p->print_ops)
		write(1, "ss\n", 3);
}
