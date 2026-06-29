/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_benchmark.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:12:49 by albustos          #+#    #+#             */
/*   Updated: 2026/06/29 17:36:36 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stack.h"
#include "../../libft/libft.h"

void	print_benchmark(t_benchmark *bench)
{
	ft_putstr_fd("[bench] disorder:   ", 2);
	ft_putnbr_fd(bench->disorder, 2);
	ft_putendl_fd("%", 2);
	ft_putstr_fd("[bench] strategy:   ", 2);
	ft_putendl_fd("pendiente", 2);
	ft_putstr_fd("[bench] total_ops:   ", 2);
	ft_putnbr_fd(bench->total_ops, 2);
	ft_putendl_fd("", 2);
}