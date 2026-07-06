/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:33:11 by mtapiado          #+#    #+#             */
/*   Updated: 2026/07/06 12:33:32 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	is_sorted(t_stack *s)
{
	t_node	*n;

	if (!s)
		return (0);
	n = s->top;
	while (n && n->next)
	{
		if (n->value > n->next->value)
			return (0);
		n = n->next;
	}
	return (1);
}

void	print_checker_result(t_program *p)
{
	if (is_sorted(p->a) && p->b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
