/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:49:33 by plang             #+#    #+#             */
/*   Updated: 2024/08/05 14:50:03 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*find_bottom(t_stack *stack_a)
{
	while (stack_a->next)
	{
		stack_a = stack_a->next;
	}
	return (stack_a);
}

t_stack	**ft_add_to_bottom(t_stack **stack_a, int nbr)
{
	t_stack	*new;
	t_stack	*bottom_node;

	new = malloc(sizeof(t_stack));
	new->next = NULL;
	new->data = nbr;
	new->index = -1;
	if (!(*stack_a))
	{
		*stack_a = new;
	}
	else
	{
		bottom_node = find_bottom(*stack_a);
		bottom_node->next = new;
	}
	return (stack_a);
}

t_stack	*get_min_data(t_stack **stack)
{
	t_stack	*node;
	t_stack	*min;
	int		flag;

	node = *stack;
	min = NULL;
	flag = 0;
	while (node != NULL)
	{
		if (node->index == -1 && (!flag || node->data < min->data))
		{
			min = node;
			flag = 1;
		}
		node = node->next;
	}
	return (min);
}

void	index_to_node(t_stack **stack_a)
{
	t_stack	*node;
	int		i;

	i = 0;
	node = get_min_data(stack_a);
	while (node)
	{
		node->index = i++;
		node = get_min_data(stack_a);
	}
}

void	init_stack(t_stack **stack_a, int argc, char **argv)
{
	char	**arguments;
	int		i;
	int		nbr;

	i = 0;
	if (argc == 2)
		arguments = ft_split(argv[1], ' ');
	else
		arguments = argv + 1;
	while (arguments[i])
	{
		nbr = ft_atoi(arguments[i]);
		ft_add_to_bottom(stack_a, nbr);
		i++;
	}
	index_to_node(stack_a);
	if (argc == 2)
		free_split(arguments);
}
