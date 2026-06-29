/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:13:02 by albustos          #+#    #+#             */
/*   Updated: 2026/06/29 12:05:22 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../include/stack.h"
#include "../../../include/operations.h"
#include "../../../include/libraries.h"

void	pb(t_program *p)
{
	ft_push(p->a, p->b);
	write(1, "pb\n", 3);
}


void	pa(t_program *p)
{
	ft_push(p->b, p->a);
	write(1, "pa\n", 3);
}
