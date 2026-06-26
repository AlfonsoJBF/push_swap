/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 19:21:12 by albustos          #+#    #+#             */
/*   Updated: 2026/06/25 19:21:12 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/stack.h"
#include "../../../include/libraries.h"

void	ft_push(t_stack *from, t_stack *to)
{
	t_node	*node;

	node = ft_stack_pop(from);
	if (node == NULL)
		return ;
	ft_stack_addfront(to, node);
}
