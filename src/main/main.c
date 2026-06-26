/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 01:22:22 by albustos          #+#    #+#             */
/*   Updated: 2026/06/25 19:52:52 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/debug.h"
#include "../../include/libraries.h"
#include "../../include/stack.h"
#include "../../include/operations.h"
#include <stdio.h>

int main(void)
{
	int nums[] = {0, 64, 13, 10, 0};
	int nums2[] = {10, 50, 60, 5, 6};
	int i = 0;
	t_node *current;
	t_stack *a = ft_stack_create();
	t_stack *b = ft_stack_create();
	if (!a)
		return (1);
	while (i < 5)
	{
		current = ft_node_create(nums[i]);
		ft_stack_addback(a, current);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		current = ft_node_create(nums2[i]);
		ft_stack_addback(b, current);
		i++;
	}
	print_stack(a);
	print_stack(b);
	ft_push(a, b);
	printf("----------------------------------");
	print_stack(a);
	print_stack(b);
	ft_free_stack(a);
	ft_free_stack(b);
	return (0);
}
