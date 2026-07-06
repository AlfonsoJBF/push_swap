/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 00:33:32 by albustos          #+#    #+#             */
/*   Updated: 2026/06/30 00:33:32 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/stack.h"
#include "../../../include/libraries.h"
#include "../../../include/algorithms.h"

static void	insertion_sort(int *sorted, int size)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < size)
	{
		key = sorted[i];
		j = i - 1;
		while (j >= 0 && sorted[j] > key)
		{
			sorted[j + 1] = sorted[j];
			j--;
		}
		sorted[j + 1] = key;
		i++;
	}
}

static int	*sort_array(int *values, int size)
{
	int	*sorted;
	int	i;

	if (!values || !size)
		return (NULL);
	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return (NULL);
	i = 0;
	while (i < size)
	{
		sorted[i] = values[i];
		i++;
	}
	insertion_sort(sorted, size);
	return (sorted);
}

int	calculate_index(int *nums, t_stack *s)
{
	t_node	*current;
	int		*sorted;
	int		i;

	if (!nums || !s)
		return (0);
	i = 0;
	sorted = sort_array(nums, s->size);
	if (!sorted)
		return (0);
	while (i < s->size)
	{
		current = ft_node_find(s, sorted[i]);
		if (!current)
			return (0);
		current->index = i;
		i++;
	}
	free(sorted);
	return (1);
}
