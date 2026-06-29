/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 02:11:36 by albustos          #+#    #+#             */
/*   Updated: 2026/06/29 02:11:36 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stack.h"
#include "../../include/libraries.h"

t_stack	*ft_stack_init(int *nums, int size)
{	
	t_stack *stack;
	t_node *current;
	int i = 0;
	
	stack = ft_stack_create();
	while (i < size)
	{
		current = ft_node_create(nums[i]);
		ft_stack_addback(stack, current);
		i++;
	}
	return (stack);
}