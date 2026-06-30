/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:52:26 by mtapiado          #+#    #+#             */
/*   Updated: 2026/06/30 10:39:50 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

# define STRAT_SIMPLE 1
# define STRAT_MEDIUM 2
# define STRAT_COMPLEX 3
# define STRAT_ADAPTIVE 4
# define FLAG_BENCH 5

// parse_structs
typedef struct s_parse_data
{
	int	*array;
	int	size;
}	t_parse_data;

typedef struct s_parse_opts
{
	int	strategy;
	int	bench;
}	t_parse_opts;

// parse_array.c

int		parse_args(int argc, char **argv, t_parse_data *data, t_parse_opts *opts);
int		parse_flags(char **tokens, t_parse_opts *opts);
int		has_duplicates(int *array, int size);
int		*tokens_to_array(char **tokens, int size);

// parse_tokens.c

char	**get_tokens(int argc, char **argv);

// parse_validate.c
int		validate_numbers(char **tokens);
int		validate_int_range(char **tokens);

//parse_utils.c

void	free_matrix(char **matrix);
int		count_tokens(char **tokens);
int		count_split_words(char **split);
int		ps_atoi(char *str);

#endif
