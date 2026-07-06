/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_exec_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:22:38 by mtapiado          #+#    #+#             */
/*   Updated: 2026/07/06 12:22:53 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	is_cmd(char *line, char *cmd)
{
	int	i;

	i = 0;
	while (line[i] && cmd[i] && line[i] == cmd[i])
		i++;
	return (line[i] == '\0' && cmd[i] == '\0');
}

int	exec_instruction(t_program *p, char *line)
{
	if (is_cmd(line, "sa\n"))
		sa(p);
	else if (is_cmd(line, "sb\n"))
		sb(p);
	else if (is_cmd(line, "ss\n"))
		ss(p);
	else if (is_cmd(line, "pa\n"))
		pa(p);
	else if (is_cmd(line, "pb\n"))
		pb(p);
	else if (is_cmd(line, "ra\n"))
		ra(p);
	else if (is_cmd(line, "rb\n"))
		rb(p);
	else if (is_cmd(line, "rr\n"))
		rr(p);
	else if (is_cmd(line, "rra\n"))
		rra(p);
	else if (is_cmd(line, "rrb\n"))
		rrb(p);
	else if (is_cmd(line, "rrr\n"))
		rrr(p);
	else
		return (0);
	return (1);
}
