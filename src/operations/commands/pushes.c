/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:13:02 by albustos          #+#    #+#             */
/*   Updated: 2026/06/27 17:21:24 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../include/stack.h"
#include "../../../include/operations.h"
#include "../../../include/libraries.h"

void	pa(t_stack *from, t_stack *to)
{
	ft_push(from, to);
	write(1, "pa\n", 3);
}


void	pb(t_stack *from, t_stack *to)
{
	ft_push(from, to);
	write(1, "pb\n", 3);
}
