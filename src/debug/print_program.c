/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 02:31:15 by albustos          #+#    #+#             */
/*   Updated: 2026/06/29 02:31:15 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/debug.h"
#include "../../include/stack.h"
#include "../../include/libraries.h"

void	print_program(t_program *p)
{
	printf("{Tamaño de a: %d | Tamaño de b: %d}\n", p->a->size, p->b->size );
	print_stack(p->a);
	print_stack(p->b);
}