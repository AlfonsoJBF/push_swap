/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 01:22:22 by albustos          #+#    #+#             */
/*   Updated: 2026/07/06 13:16:12 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../include/algorithms.h"
#include "../../include/debug.h"
#include "../../include/libraries.h"
#include "../../include/parse.h"
#include "../../include/stack.h"

static void	solve_program(t_program *p, t_parse_opts *o)
{
	if (o->strategy == 1)
	{
		selection_sort(p);
		p->bench->strategy = ft_strdup("Simple / O(n²)");
	}
	else if (o->strategy == 2)
	{
		chunk_sort(p);
		p->bench->strategy = ft_strdup("Medium / O(n log n)");
	}
	else if (o->strategy == 3)
	{
		k_sort(p);
		p->bench->strategy = ft_strdup("Complex / O(n log n)");
	}
	else if (o->strategy == 4)
	{
		adaptative_sort(p);
		p->bench->strategy = ft_strdup("Adaptative / O(n log n)");
	}
	if (o->bench)
		print_benchmark(p->bench);
}

int	main(int argc, char **argv)
{
	t_program		*p;
	t_parse			*parse;

	if (argc == 1)
		return (0);
	parse = orchestate_parse(argc, argv);
	if (!parse->data->array)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	p = ft_program_init(parse->data->array, parse->data->size);
	if (!p)
		return (1);
	p->bench->disorder = compute_disorder(p->a);
	calculate_index(parse->data->array, p->a);
	solve_program(p, parse->opts);
	ft_program_close(p);
	free_parse(parse);
	return (0);
}
