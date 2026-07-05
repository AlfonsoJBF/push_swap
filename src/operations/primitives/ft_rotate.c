/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 23:09:35 by albustos          #+#    #+#             */
/*   Updated: 2026/06/25 23:09:35 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/stack.h"
#include "../../../include/libraries.h"

void	ft_rotate(t_stack *stack)
{
	t_node	*tmp;

	tmp = ft_stack_pop(stack);
	ft_stack_addback(stack, tmp);
}
