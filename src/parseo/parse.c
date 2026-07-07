/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 23:12:00 by albustos          #+#    #+#             */
/*   Updated: 2026/07/04 23:12:00 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

t_parse	*orchestate_parse(int argc, char **argv)
{
	t_parse			*parse;
	t_parse_data	*pd;
	t_parse_opts	*po;

	parse = malloc(sizeof(t_parse));
	if (!parse)
		return (NULL);
	pd = malloc(sizeof(t_parse_data));
	if (!pd)
		return (NULL);
	po = malloc(sizeof(t_parse_opts));
	if (!po)
		return (NULL);
	parse->data = pd;
	parse->opts = po;
	p_args(argc, argv, pd, po);
	if (!parse->data->array)
		return (free_parse(parse), NULL);
	return (parse);
}

void	free_parse(t_parse *parse)
{
	free(parse->data->array);
	parse->data->array = NULL;
	free(parse->data);
	parse->data = NULL;
	free(parse->opts);
	parse->opts = NULL;
	free(parse);
	parse = NULL;
}
