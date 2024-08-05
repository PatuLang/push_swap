/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:58:58 by plang             #+#    #+#             */
/*   Updated: 2024/08/05 14:50:03 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_2(t_stack **stack_a)
{
	int	first;
	int	second;

	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	if (first > second)
		do_sa(stack_a);
}

void	sort_3(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	third = (*stack_a)->next->next->index;
	if (first > second && second < third && third > first)
		do_sa(stack_a);
	else if (first > second && second > third && third < first)
	{
		do_sa(stack_a);
		do_rra(stack_a);
	}
	else if (first > second && second < third && second < first)
		do_ra(stack_a);
	else if (first < second && second > third && third > first)
	{
		do_sa(stack_a);
		do_ra(stack_a);
	}
	else if (first < second && second > third && third < first)
		do_rra(stack_a);
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = fetch_min_n_push(*stack_a);
	while ((*stack_a)->index != min)
		do_rra(stack_a);
	do_pb(stack_a, stack_b);
	sort_3(stack_a);
	do_pa(stack_a, stack_b);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b, int steps)
{
	int	min;

	min = fetch_min_n_push(*stack_a);
	while ((*stack_a)->index != min)
	{
		if (steps < 2)
			do_ra(stack_a);
		else
			do_rra(stack_a);
	}
	do_pb(stack_a, stack_b);
	min = fetch_min_n_push(*stack_a);
	while ((*stack_a)->index != min)
	{
		if (steps < 2)
			do_rra(stack_a);
		else
			do_ra(stack_a);
	}
	do_pb(stack_a, stack_b);
	sort_3(stack_a);
	do_pa(stack_a, stack_b);
	do_pa(stack_a, stack_b);
}

void	short_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	steps;

	steps = get_steps(*stack_a);
	if (ft_lstsize_stack(stack_a) == 2)
		sort_2(stack_a);
	else if (ft_lstsize_stack(stack_a) == 3)
		sort_3(stack_a);
	else if (ft_lstsize_stack(stack_a) == 4)
		sort_4(stack_a, stack_b);
	else
		sort_5(stack_a, stack_b, steps);
}
