/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:01:40 by mtapiado          #+#    #+#             */
/*   Updated: 2026/07/06 12:33:42 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	init_checker(int argc, char **argv, t_parse **parse, t_program **p)
{
	*parse = orchestate_parse(argc, argv);
	if (!*parse || !(*parse)->data || !(*parse)->data->array)
		return (0);
	*p = ft_program_init((*parse)->data->array, (*parse)->data->size);
	if (!*p)
		return (0);
	(*p)->print_ops = 0;
	return (1);
}

static int	checker_error(t_program *p, t_parse *parse)
{
	write(2, "Error\n", 6);
	if (p)
		ft_program_close(p);
	if (parse)
		free_parse(parse);
	return (1);
}

int	main(int argc, char **argv)
{
	t_program	*p;
	t_parse		*parse;

	if (argc == 1)
		return (0);
	p = NULL;
	parse = NULL;
	if (!init_checker(argc, argv, &parse, &p))
		return (checker_error(p, parse));
	if (!read_instructions(p))
		return (checker_error(p, parse));
	print_checker_result(p);
	ft_program_close(p);
	free_parse(parse);
	return (0);
}
