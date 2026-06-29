/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:19:49 by albustos          #+#    #+#             */
/*   Updated: 2026/06/29 02:54:06 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/stack.h"
#include "../../../include/operations.h"
#include "../../../include/libraries.h"

void	ra(t_program *p)
{
	ft_rotate(p->a);
	write(1, "ra\n", 3);
}

void	rb(t_program *p)
{
	ft_rotate(p->b);
	write(1, "rb\n", 3);
}

void	rr(t_program *p)
{
	ft_rotate(p->a);
	ft_rotate(p->b);
	write(1, "rr\n", 3);
}
