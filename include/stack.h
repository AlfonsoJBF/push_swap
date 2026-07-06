/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 22:12:21 by albustos          #+#    #+#             */
/*   Updated: 2026/07/06 11:46:32 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

/* BENCHMARK */

typedef struct s_metrics
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_metrics;

typedef struct s_benchmark
{
	int			total_ops;
	int			disorder;
	t_metrics	*metrics;
	char		*strategy;
}	t_benchmark;

/* NODOS */

typedef struct s_node
{
	int				value;
	int				index;
	int				target_pos;
	struct s_node	*next;
}	t_node;

t_node		*ft_node_create(int value);

/* STACKS */

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

t_stack		*ft_stack_create(void);
t_stack		*ft_stack_init(int *nums, int size);
t_node		*ft_node_find(t_stack *s, int value);
t_node		*ft_stack_last(t_stack *stack);
t_node		*ft_stack_pop(t_stack *stack);
t_node		*ft_stack_pull(t_stack *stack);
void		ft_stack_addback(t_stack *stack, t_node *node);
void		ft_stack_addfront(t_stack *stack, t_node *node);
void		ft_free_stack(t_stack *stack);
void		ft_stack_delete_node(t_stack *stack, t_node *node);

/* PROGRAM */

typedef struct s_program
{
	t_stack		*a;
	t_stack		*b;
	t_benchmark	*bench;
	int			print_ops;
}	t_program;

t_program	*ft_program_init(int *nums, int size);
void		ft_bench_init(t_program *p);
void		ft_program_close(t_program *p);

#endif
