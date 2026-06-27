/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 14:21:27 by albustos          #+#    #+#             */
/*   Updated: 2026/06/27 16:33:51 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stack.h"

void	sort_three(t_stack *stack)
{
	t_node *current;
	int a;
	int b;
	int c;
	
	current = stack->top;
	a = current->value;
	current = current->next;
	b = current->value;
	current = current->next;
	c = current->value;
}
