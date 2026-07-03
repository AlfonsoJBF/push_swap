/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 01:22:22 by albustos          #+#    #+#             */
/*   Updated: 2026/07/03 02:56:04 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../libft/libft.h"
#include "../../include/algorithms.h"
#include "../../include/debug.h"
#include "../../include/libraries.h"
#include "../../include/parse.h"
#include "../../include/stack.h"

void	solve_program(t_program *p, t_parse_opts *o)
{
	ft_printf("Inicializando en modo: %d", o->strategy);
	if (o->strategy == 1)
	{
		selection_sort(p);
		p->bench->strategy = ft_strdup("Simple / O(n²)");
	}
	else if (o->strategy == 2)
		chunk_sort(p);
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
	if(o->bench)
		print_benchmark(p->bench);
}

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
	parse_args(argc, argv, pd, po);

	return(parse);
}

void	free_parse(t_parse *parse)
{
	free(parse->data->array);
	free(parse->data);
	free(parse->opts);
	free(parse);
}

int	main(int argc, char **argv)
{
	t_program		*p;
	t_parse	*parse;

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
	calculate_index(parse->data->array, p->a);
	solve_program(p, parse->opts);
	ft_program_close(p);
	free_parse(parse);
	return (0);
}
