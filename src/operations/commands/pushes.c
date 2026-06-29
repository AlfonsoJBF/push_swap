/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:13:02 by albustos          #+#    #+#             */
/*   Updated: 2026/06/29 17:46:03 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../include/stack.h"
#include "../../../include/operations.h"
#include "../../../include/libraries.h"

void	pb(t_program *p)
{
	ft_push(p->a, p->b);
	p->bench->total_ops++;
	p->bench->metrics->pb++;
	write(1, "pb\n", 3);
}


void	pa(t_program *p)
{
	ft_push(p->b, p->a);
	p->bench->total_ops++;
	p->bench->metrics->pa++;
	write(1, "pa\n", 3);
}
