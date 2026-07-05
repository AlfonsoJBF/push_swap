/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:51:03 by mtapiado          #+#    #+#             */
/*   Updated: 2026/07/05 14:55:49 by mtapiado         ###   ########.fr       */
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

static int	parse_array_error(t_parse_data *data)
{
	free(data->array);
	data->array = NULL;
	data->size = 0;
	return (0);
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

int	p_args(int argc, char **argv, t_parse_data *data, t_parse_opts *opts)
{
	char	**tokens;

	data->array = NULL;
	data->size = 0;
	tokens = get_tokens(argc, argv);
	if (!tokens)
		return (0);
	if (!parse_flags(tokens, opts)
		|| !validate_numbers(tokens) || !validate_int_range(tokens))
	{
		free_matrix(tokens);
		return (0);
	}
	data->size = count_tokens(tokens);
	data->array = tokens_to_array(tokens, data->size);
	free_matrix(tokens);
	if (!data->array)
		return (0);
	if (has_duplicates(data->array, data->size))
		return (parse_array_error(data));
	return (1);
}
