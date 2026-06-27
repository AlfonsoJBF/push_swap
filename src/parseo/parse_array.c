/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:51:03 by mtapiado          #+#    #+#             */
/*   Updated: 2026/06/26 12:19:50 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	*tokens_to_array(char **tokens, int size)
{
	int	*array;
	int	i;

	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array[i] = ft_atoi(tokens[i]);
		i++;
	}
	return (array);
}

int	has_duplicates(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parse_args(int argc, char **argv, int **array, int *size)
{
	char	**tokens;

	tokens = get_tokens(argc, argv);
	if (!tokens)
		return (0);
	if (!validate_numbers(tokens) || !validate_int_range(tokens))
	{
		free_matrix(tokens);
		return (0);
	}
	*size = count_tokens(tokens);
	*array = tokens_to_array(tokens, *size);
	free_matrix(tokens);
	if (!*array)
		return (0);
	if (has_duplicates(*array, *size))
	{
		free(*array);
		*array = NULL;
		return (0);
	}
	return (1);
}
