/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:49:38 by plang             #+#    #+#             */
/*   Updated: 2024/02/13 11:12:53 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize_stack(t_stack **stack)
{
	int		count;
	t_stack	*temp;

	count = 0;
	temp = *stack;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

int	is_it_sorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next != NULL)
	{
		if (temp->index > temp->next->index)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2 && !argv[1][0])
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	check_input(argc, argv);
	init_stack(&stack_a, argc, argv);
	if (is_it_sorted(stack_a))
		sort_stack(&stack_a, &stack_b);
	clear_free_stack(&stack_a);
	return (0);
}
