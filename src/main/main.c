/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 01:22:22 by albustos          #+#    #+#             */
/*   Updated: 2026/06/29 15:03:35 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/debug.h"
#include "../../include/libraries.h"
#include "../../include/stack.h"
#include "../../include/operations.h"
#include "../../include/parse.h"
#include "../../include/algorithms.h"
#include <stdio.h>

// int main(int argc, char **argv)
// {
// 	int *nums;
// 	int nums_size;
// 	t_program *p;

// 	parse_args(argc, argv, &nums, &nums_size);
// 	if(!nums || !nums_size)
// 	{
// 		write(1, "Error", 5);
// 		return (1);
// 	}
// 	p = ft_program_init(nums, nums_size);
// 	if (!p)
// 		return (1);
// 	print_program(p);
// 	pa(p);
// 	print_program(p);
// 	pa(p);
// 	print_program(p);
// 	pa(p);
// 	print_program(p);
// 	sa(p);
// 	print_program(p);
// 	ra(p);
// 	print_program(p);
// 	rra(p);
// 	print_program(p);
// 	pb(p);
// 	print_program(p);
// 	sb(p);
// 	print_program(p);
// 	rb(p);
// 	print_program(p);
// 	rrb(p);
// 	print_program(p);
// 	ss(p);
// 	print_program(p);
// 	rr(p);
// 	print_program(p);
// 	rrr(p);
// 	print_program(p);
// 	pb(p);
// 	print_program(p);
// 	pb(p);
// 	pb(p);
// 	print_program(p);
// 	ft_program_close(p);
// 	free(nums);
// 	/* printf("{Tamaño de a: %d | Tamaño de b: %d}\n", a->size, b->size );
// 	print_stack(a);
// 	print_stack(b);
// 	ft_push(a, b);
// 	printf("----------------------------------\n");
// 	printf("{Tamaño de a: %d | Tamaño de b: %d}\n", a->size, b->size );
// 	print_stack(a);
// 	print_stack(b);
// 	ft_swap(b);
// 	ft_swap(a);
// 	printf("----------------------------------\n");
// 	printf("{Tamaño de a: %d | Tamaño de b: %d}\n", a->size, b->size );
// 	print_stack(a);
// 	print_stack(b);
// 	ft_rotate(a);
// 	ft_reverse_rotate(b);
// 	printf("----------------------------------\n");
// 	printf("{Tamaño de a: %d | Tamaño de b: %d}\n", a->size, b->size );
// 	print_stack(a);
// 	print_stack(b);
// 	ft_free_stack(a);
// 	ft_free_stack(b); */
// 	return (0);
// }

#include "../../include/algorithms.h"
#include "../../include/debug.h"
#include "../../include/libraries.h"
#include "../../include/parse.h"
#include "../../include/stack.h"

int	main(int argc, char **argv)
{
	int			*nums;
	int			nums_size;
	t_program	*p;
	t_node	*min;

	if (argc == 1)
		return (0);
	nums = NULL;
	nums_size = 0;
	parse_args(argc, argv, &nums, &nums_size);
	if (!nums)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	p = ft_program_init(nums, nums_size);
	free(nums);
	if (!p)
		return (1);
	print_program(p);
	min = find_min(p->a);
	printf("El valor minimo es: %d\n", min->value);
	selection_sort(p);
	print_program(p);
	ft_program_close(p);
	return (0);
}