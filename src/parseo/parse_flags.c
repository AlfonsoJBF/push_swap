/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:35:54 by mtapiado          #+#    #+#             */
/*   Updated: 2026/06/30 11:05:31 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	flag_id(char *token)
{
	if (!ft_strncmp(token, "--simple", 9))
		return (STRAT_SIMPLE);
	if (!ft_strncmp(token, "--medium", 9))
		return (STRAT_MEDIUM);
	if (!ft_strncmp(token, "--complex", 10))
		return (STRAT_COMPLEX);
	if (!ft_strncmp(token, "--adaptive", 11))
		return (STRAT_ADAPTIVE);
	if (!ft_strncmp(token, "--bench", 8))
		return (FLAG_BENCH);
	return (0);
}

static void	apply_flag(int flag, t_parse_opts *opts, int *has_strategy)
{
	if (flag == FLAG_BENCH)
		opts->bench = 1;
	else if (*has_strategy)
		*has_strategy = -1;
	else
	{
		*has_strategy = 1;
		opts->strategy = flag;
	}
}

static void	remove_token(char **tokens, int pos)
{
	free(tokens[pos]);
	while (tokens[pos + 1])
	{
		tokens[pos] = tokens[pos + 1];
		pos++;
	}
	tokens[pos] = NULL;
}

int	parse_flags(char **tokens, t_parse_opts *opts)
{
	int	i;
	int	flag;
	int	has_strategy;

	i = 0;
	has_strategy = 0;
	opts->strategy = STRAT_ADAPTIVE;
	opts->bench = 0;
	while (tokens[i])
	{
		flag = flag_id(tokens[i]);
		if (!flag)
			i++;
		else
		{
			apply_flag(flag, opts, &has_strategy);
			remove_token(tokens, i);
		}
	}
	return (has_strategy != -1);
}
