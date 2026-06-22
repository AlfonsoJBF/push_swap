/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 01:22:22 by albustos          #+#    #+#             */
/*   Updated: 2026/06/21 02:14:01 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stack.h"
#include "../../include/libraries.h"


static void print_stack(t_stack *stack)
{
    t_node *tmp;

    if (!stack)
    {
        printf("stack is NULL\n");
        return;
    }

    tmp = stack->top;
    while (tmp)
    {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
}

int main(void)
{
	int nums[] = {0, 64, 13, 10, 0};
	int i = 0;
	t_node *current;
	t_stack *a = ft_stack_create();
	if (!a)
		return (1);
	while (i < 5)
	{
		current = ft_node_create(nums[i]);
		ft_stack_addbck(a, current);
		i++;
	}
	print_stack(a);
	ft_free_stack(a);
	return (0);
}
