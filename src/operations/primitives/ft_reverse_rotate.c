/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 22:58:11 by albustos          #+#    #+#             */
/*   Updated: 2026/06/25 22:58:11 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/stack.h"
#include "../../../include/libraries.h"

void	ft_reverse_rotate(t_stack *stack)
{
	t_node *tmp;

	tmp = ft_stack_pull(stack);
	ft_stack_addfront(stack, tmp);
}