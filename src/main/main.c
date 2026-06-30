/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 01:22:22 by albustos          #+#    #+#             */
/*   Updated: 2026/06/30 14:58:22 by albustos         ###   ########.fr       */
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
		selection_sort(p);
	else if (o->strategy == 2)
		ft_printf("Algoritmo --medium-- en proceso");
	else if (o->strategy == 3)
		k_sort(p);
	else if (o->strategy == 4)
		ft_printf("Algoritmo --adaptative-- en proceso");
	
	if(o->bench)
		print_benchmark(p->bench);
}


int	main(int argc, char **argv)
{
	t_program		*p;
	t_parse_data	*pd;
	t_parse_opts	*po;

	
	pd = malloc(sizeof(t_parse_data));
	if (!pd)
		return (1);
	po = malloc(sizeof(t_parse_opts));
	if (!po)
		return (1);
	if (argc == 1)
		return (0);
	parse_args(argc, argv, pd, po);
	if (!pd->array)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	p = ft_program_init(pd->array, pd->size);
	if (!p)
		return (1);
	print_program(p);
	calculate_index(pd->array, p->a);
	solve_program(p, po);
	ft_program_close(p);
	free(pd);
	free(po);
	return (0);
}