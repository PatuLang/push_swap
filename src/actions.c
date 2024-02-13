/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:49:12 by plang             #+#    #+#             */
/*   Updated: 2024/02/13 11:12:53 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*top;
	t_stack	*temp;
	t_stack	*tail;

	top = *stack;
	temp = *stack;
	tail = *stack;
	while (tail->next)
		tail = tail->next;
	top = top->next;
	temp->next = top->next;
	top->next = temp;
	*stack = top;
}

void	rotate(t_stack **stack)
{
	t_stack	*top;
	t_stack	*temp;
	t_stack	*tail;

	top = *stack;
	temp = *stack;
	tail = *stack;
	while (tail->next)
		tail = tail->next;
	top = top->next;
	tail->next = temp;
	temp->next = NULL;
	*stack = top;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*old_top;
	t_stack	*to_bottom;
	t_stack	*to_top;

	old_top = *stack;
	to_bottom = *stack;
	to_top = *stack;
	while (to_top->next)
		to_top = to_top->next;
	while (to_bottom->next->next != NULL)
		to_bottom = to_bottom->next;
	to_top->next = old_top;
	to_bottom->next = NULL;
	*stack = to_top;
}

void	push(t_stack **dest_stack, t_stack **src_stack)
{
	t_stack	*from_stack;
	t_stack	*to_stack;
	t_stack	*temp;

	from_stack = *src_stack;
	to_stack = *dest_stack;
	temp = from_stack;
	from_stack = from_stack->next;
	temp->next = to_stack;
	*dest_stack = temp;
	*src_stack = from_stack;
}

int	get_steps(t_stack *stack_a)
{
	int		steps;
	t_stack	*temp;
	int		min_pos;
	t_stack	*check;

	steps = 0;
	temp = stack_a;
	check = stack_a;
	min_pos = temp->index;
	while (temp != NULL)
	{
		if (temp->index < min_pos)
			min_pos = temp->index;
		temp = temp->next;
	}
	if (check->next->index == min_pos)
		steps = 1;
	else
		steps = 3;
	return (steps);
}
