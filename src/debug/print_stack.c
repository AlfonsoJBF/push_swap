/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 19:11:11 by albustos          #+#    #+#             */
/*   Updated: 2026/06/22 19:21:22 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libraries.h"
#include "../../include/stack.h"

void print_stack(t_stack *stack)
{
    t_node *tmp;

    if (!stack)
    {
        printf("stack is NULL\n");
        return;
    }

    tmp = stack->top;
    printf("[");
    while (tmp)
    {
		if (tmp->next == NULL)
		{
        printf(" %d ", tmp->value);
		break ;
		}
        printf(" %d,", tmp->value);
        tmp = tmp->next;
    }
    printf("]\n");
}
