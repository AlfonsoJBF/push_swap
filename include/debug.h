/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 02:14:36 by albustos          #+#    #+#             */
/*   Updated: 2026/06/29 02:14:36 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

#include "stack.h"

void	print_stack(t_stack *stack);
void	print_program(t_program *p);
void	print_benchmark(t_benchmark *bench);

#endif
