/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:51:33 by mtapiado          #+#    #+#             */
/*   Updated: 2026/06/26 12:42:10 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	count_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		i++;
	return (i);
}

int	count_split_words(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
		i++;
	return (i);
}
