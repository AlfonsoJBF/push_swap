/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:51:15 by mtapiado          #+#    #+#             */
/*   Updated: 2026/06/29 17:05:06 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	count_total_tokens(int argc, char **argv)
{
	char	**split;
	int		i;
	int		total;

	i = 1;
	total = 0;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (-1);
		if (split[0] == NULL)
		{
			free_matrix(split);
			return (-1);
		}
		total += count_split_words(split);
		free_matrix(split);
		i++;
	}
	return (total);
}

static int	fill_tokens(char **tokens, char **split, int *j)
{
	int	i;

	i = 0;
	while (split[i])
	{
		tokens[*j] = ft_strdup(split[i]);
		if (!tokens[*j])
			return (0);
		(*j)++;
		i++;
	}
	return (1);
}

static char	**free_tokens_error(char **tokens, char **split, int j)
{
	free_matrix(split);
	tokens[j] = NULL;
	free_matrix(tokens);
	return (NULL);
}

char	**get_tokens(int argc, char **argv)
{
	char	**tokens;
	char	**split;
	int		total;
	int		i;
	int		j;

	total = count_total_tokens(argc, argv);
	if (total < 0)
		return (NULL);
	tokens = malloc(sizeof(char *) * (total + 1));
	if (!tokens)
		return (NULL);
	i = 1;
	j = 0;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split || !fill_tokens(tokens, split, &j))
			return (free_tokens_error(tokens, split, j));
		free_matrix(split);
		i++;
	}
	tokens[j] = NULL;
	return (tokens);
}
