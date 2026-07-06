/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:02:15 by mtapiado          #+#    #+#             */
/*   Updated: 2026/07/06 12:32:41 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../../libft/libft.h"
# include "../../include/algorithms.h"
# include "../../include/libraries.h"
# include "../../include/parse.h"
# include "../../include/stack.h"
# include "../../include/operations.h"

int		exec_instruction(t_program *p, char *line);
int		read_instructions(t_program *p);
int		is_sorted(t_stack *s);
void	print_checker_result(t_program *p);

#endif