/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 13:49:28 by mtapiado          #+#    #+#             */
/*   Updated: 2026/07/01 18:18:12 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/stack.h"
#include "../../../include/libraries.h"
#include "../../../include/algorithms.h"
#include "../../../include/operations.h"

// static int	get_chunk_size(int size)
// {
// 	int	i;

// 	i = 1;
// 	while (i * i <= size)
// 		i++;
// 	return (i - 1);
// }

static int	get_chunk_size(int size)
{
	if (size <= 100)
		return (20);
	return (50);
}

static void	push_chunk_node(t_program *p, int index, int limit, int chunk)
{
	pb(p);
	if (index < limit - (chunk / 2))
		rb(p);
}

static void	move_next_chunk_to_top_a(t_program *p, int limit)
{
	t_node	*node;
	int		pos;
	int		size;

	node = p->a->top;
	pos = 0;
	while (node && node->index >= limit)
	{
		node = node->next;
		pos++;
	}
	if (!node)
		return ;
	size = p->a->size;
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(p);
	else
		while (pos++ < size)
			rra(p);
}

static void	push_chunks_to_b(t_program *p, int size, int chunk)
{
	int	limit;
	int	pushed;
	int	index;

	limit = chunk;
	pushed = 0;
	while (p->a->size > 0)
	{
		index = p->a->top->index;
		if (index < limit)
		{
			push_chunk_node(p, index, limit, chunk);
			pushed++;
			if (pushed == limit - (chunk/4) && limit < size)
			{
				limit += chunk;
				if (limit > size)
					limit = size;
			}
		}
		else
			move_next_chunk_to_top_a(p, limit);
	}
}

void	chunk_sort(t_program *p)
{
	int	size;
	int	chunk;
	int	i;

	i = 0;
	size = p->a->size;
	chunk = get_chunk_size(size);
	push_chunks_to_b(p, size, chunk);
	while (i < 2)
	{
		move_max_to_top_b(p);
		pa(p);
		i++;
	}
	while (p->b->size > 0)
	{
		move_max_to_top_b(p);
		pa(p);
	}
}
