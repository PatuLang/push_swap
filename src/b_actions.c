/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_actions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:49:17 by plang             #+#    #+#             */
/*   Updated: 2024/02/13 11:12:53 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_sb(t_stack **stack)
{
	swap(stack);
	ft_printf("sb\n");
}

void	do_rb(t_stack **stack)
{
	rotate(stack);
	ft_printf("rb\n");
}

void	do_rrb(t_stack **stack)
{
	reverse_rotate(stack);
	ft_printf("rrb\n");
}

void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}
