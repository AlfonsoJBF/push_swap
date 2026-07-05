/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_program_close.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 02:24:25 by albustos          #+#    #+#             */
/*   Updated: 2026/06/29 02:24:25 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stack.h"
#include "../../include/libraries.h"

void	ft_program_close(t_program *p)
{
	if (!p)
		return ;
	ft_free_stack(p->a);
	ft_free_stack(p->b);
	free(p->bench->metrics);
	free(p->bench);
	free(p);
}
