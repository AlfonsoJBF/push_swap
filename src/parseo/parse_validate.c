/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:51:48 by mtapiado          #+#    #+#             */
/*   Updated: 2026/06/26 11:59:10 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	is_valid_number(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	validate_numbers(char **tokens)
{
	int	i;

	if (!tokens || !tokens[0])
		return (0);
	i = 0;
	while (tokens[i])
	{
		if (!is_valid_number(tokens[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_int_range(char *str)
{
	int		i;
	int		digit;
	long	num;
	long	limit;

	i = 0;
	num = 0;
	limit = INT_MAX;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			limit = -(long)INT_MIN;
		i++;
	}
	while (str[i])
	{
		digit = str[i] - '0';
		if (num > (limit - digit) / 10)
			return (0);
		num = (num * 10) + digit;
		i++;
	}
	return (1);
}

int	validate_int_range(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		if (!is_int_range(tokens[i]))
			return (0);
		i++;
	}
	return (1);
}
