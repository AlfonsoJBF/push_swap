/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:13:02 by albustos          #+#    #+#             */
/*   Updated: 2026/06/29 02:41:20 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../include/stack.h"
#include "../../../include/operations.h"
#include "../../../include/libraries.h"

void	pa(t_program *p)
{
	ft_push(p->a, p->b);
	write(1, "pa\n", 3);
}


void	pb(t_program *p)
{
	ft_push(p->b, p->a);
	write(1, "pb\n", 3);
}
