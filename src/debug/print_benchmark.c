/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_benchmark.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:12:49 by albustos          #+#    #+#             */
/*   Updated: 2026/06/30 16:00:28 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stack.h"
#include "../../libft/libft.h"

void	print_benchmark(t_benchmark *bench)
{
	ft_printf_error("[bench] disorder:  %d%%\n",bench->disorder);
	ft_printf_error("[bench] strategy:  %s\n",bench->strategy);
	ft_printf_error("[bench] total_ops:  %d\n",bench->total_ops);

}