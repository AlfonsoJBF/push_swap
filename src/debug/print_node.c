/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 01:08:32 by albustos          #+#    #+#             */
/*   Updated: 2026/06/30 01:08:32 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stack.h"
#include "../../libft/libft.h"

void	print_node(t_node *n)
{
	ft_printf("{ ");
	ft_printf(" Value: %d,", n->value);
	ft_printf(" Index: %d ", n->index);
	ft_printf("}\n");
}