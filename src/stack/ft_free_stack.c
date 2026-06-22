/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 01:37:54 by albustos          #+#    #+#             */
/*   Updated: 2026/06/21 01:43:02 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stack.h"
#include "../../include/libraries.h"

void	ft_free_stack(t_stack *stack){
	t_node	*tmp;
	int		i;

	tmp = stack->top;
	i = 0;
	while (i <= stack->size)
	{
		tmp = tmp->next;
		free(stack->top);
		stack->top = tmp;
		i++;
	}
	free(stack);
}
