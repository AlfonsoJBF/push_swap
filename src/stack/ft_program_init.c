/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_program_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 02:18:05 by albustos          #+#    #+#             */
/*   Updated: 2026/06/29 02:18:05 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stack.h"
#include "../../include/libraries.h"

t_program	*ft_program_init(int *nums, int size)
{
	t_program	*p;

	if (!nums || !size)
		return (NULL);
	p = malloc(sizeof(t_program));
	if (!p)
		return (NULL);
	p->a = ft_stack_init(nums, size);
	p->b = ft_stack_create();
	p->print_ops = 1;
	ft_bench_init(p);
	return (p);
}
