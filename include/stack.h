/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 22:12:21 by albustos          #+#    #+#             */
/*   Updated: 2026/06/21 01:37:24 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
// NODOS
typedef struct s_node
{
    int             value;
    int             index;
    int             pos;
    int             target_pos;
    struct s_node   *next;
}   t_node;

t_node *ft_node_create(int value);

// STACKS
typedef struct s_stack
{
    t_node  *top;
    int     size;
}   t_stack;

t_stack	*ft_stack_create(void);
t_node	*ft_stack_last(t_stack *stack);
void	ft_stack_addback(t_stack *stack, t_node *node );
void	ft_free_stack(t_stack *stack);


#endif
