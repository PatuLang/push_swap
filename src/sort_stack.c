/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:49:42 by plang             #+#    #+#             */
/*   Updated: 2024/02/13 11:12:53 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	fetch_min_n_push(t_stack *stack_a)
{
	t_stack	*temp;
	int		min_pos;

	temp = stack_a;
	min_pos = temp->index;
	while (temp != NULL)
	{
		if (temp->index < min_pos)
			min_pos = temp->index;
		temp = temp->next;
	}
	return (min_pos);
}

int	get_bit_limit(int biggest_index)
{
	int	bit_limit;

	bit_limit = 0;
	while ((biggest_index >> bit_limit) != 0)
		bit_limit++;
	return (bit_limit);
}

void	radix_small(t_stack **stack_a, t_stack **stack_b, int bit_limit, int i)
{
	int	size;

	while (i < bit_limit && (is_it_sorted(*stack_a)))
	{
		size = ft_lstsize_stack(stack_a);
		while ((*stack_a) && 0 < size-- && (is_it_sorted(*stack_a)))
		{
			if (((*stack_a)->index >> i & 1) == 0)
				do_pb(stack_a, stack_b);
			else
				do_ra(stack_a);
		}
		i++;
		while (*stack_b)
			do_pa(stack_a, stack_b);
	}
}

void	radix_big(t_stack **stack_a, t_stack **stack_b, int bit_limit, int i)
{
	int	size;

	while (i < bit_limit && (is_it_sorted(*stack_a)))
	{
		size = ft_lstsize_stack(stack_a);
		while ((*stack_a) && 0 < size-- && (is_it_sorted(*stack_a)))
		{
			if (((*stack_a)->index >> i & 1) == 0)
				do_pb(stack_a, stack_b);
			else
				do_ra(stack_a);
		}
		i++;
		size = ft_lstsize_stack(stack_b);
		while ((*stack_b) && 0 < size--)
		{
			if (((*stack_b)->index >> i & 1) == 0)
				do_rb(stack_b);
			else
				do_pa(stack_a, stack_b);
		}
	}
	while (*stack_b)
		do_pa(stack_a, stack_b);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	biggest_index;
	int	bit_limit;
	int	i;

	biggest_index = ft_lstsize_stack(stack_a) - 1;
	bit_limit = get_bit_limit(biggest_index);
	i = 0;
	if (ft_lstsize_stack(stack_a) <= 5 && ft_lstsize_stack(stack_a) >= 2)
		short_sort(stack_a, stack_b);
	else if (ft_lstsize_stack(stack_a) > 5 && ft_lstsize_stack(stack_a) < 10)
		radix_small(stack_a, stack_b, bit_limit, i);
	else
		radix_big(stack_a, stack_b, bit_limit, i);
}
