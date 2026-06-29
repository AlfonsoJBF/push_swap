/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:20:51 by albustos          #+#    #+#             */
/*   Updated: 2026/06/29 11:00:46 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/stack.h"
#include "../../../include/operations.h"
#include "../../../include/libraries.h"

void	rra(t_program *p)
{
	ft_reverse_rotate(p->a);
	write(1, "rra\n", 4);
}

void	rrb(t_program *p)
{
	ft_reverse_rotate(p->b);
	write(1, "rrb\n", 4);
}

void	rrr(t_program *p)
{
	ft_reverse_rotate(p->a);
	ft_reverse_rotate(p->b);
	write(1, "rrr\n", 4);
}

