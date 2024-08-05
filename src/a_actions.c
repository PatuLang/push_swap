/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_actions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:48:40 by plang             #+#    #+#             */
/*   Updated: 2024/08/05 14:50:03 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_sa(t_stack **stack)
{
	swap(stack);
	ft_printf("sa\n");
}

void	do_ra(t_stack **stack)
{
	rotate(stack);
	ft_printf("ra\n");
}

void	do_rra(t_stack **stack)
{
	reverse_rotate(stack);
	ft_printf("rra\n");
}

void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
}
