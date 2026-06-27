/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:52:26 by mtapiado          #+#    #+#             */
/*   Updated: 2026/06/26 11:52:32 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

// parse_array.c

int		parse_args(int argc, char **argv, int **array, int *size);
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
