/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_benchmark.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:12:49 by albustos          #+#    #+#             */
/*   Updated: 2026/07/04 22:11:04 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stack.h"
#include "../../libft/libft.h"

static void	print_disorder(int disorder)
{
	int percent;
	int decimal;

	percent = disorder / 100;
	decimal =  disorder % 100;
	ft_printf_error("[bench] disorder:  %d.%d%%\n", percent, decimal);
	
}

void	print_benchmark(t_benchmark *bench)
{
	print_disorder(bench->disorder);
	ft_printf_error("[bench] strategy:  %s\n",bench->strategy);
	ft_printf_error("[bench] total_ops:  %d\n",bench->total_ops);

}