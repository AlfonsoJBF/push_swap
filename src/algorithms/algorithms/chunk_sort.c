/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 13:49:28 by mtapiado          #+#    #+#             */
/*   Updated: 2026/06/30 17:48:04 by mtapiado         ###   ########.fr       */
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
	return (45);
}

static void	update_limit(int *limit, int chunk, int size)
{
	*limit += chunk;
	if (*limit > size)
		*limit = size;
}

static void	push_chunk_node(t_program *p, int index, int limit, int chunk)
{
	pb(p);
	if (index < limit - (chunk / 2))
		rb(p);
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
			if (pushed == limit && limit < size)
				update_limit(&limit, chunk, size);
		}
		else
			ra(p);
	}
}

void	chunk_sort(t_program *p)
{
	int	size;
	int	chunk;

	size = p->a->size;
	chunk = get_chunk_size(size);
	push_chunks_to_b(p, size, chunk);
	while (p->b->size > 0)
	{
		move_max_to_top_b(p);
		pa(p);
	}
}
