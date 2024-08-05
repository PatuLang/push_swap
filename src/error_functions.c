/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:49:24 by plang             #+#    #+#             */
/*   Updated: 2024/08/05 14:50:03 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error_exit_ac2(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_split(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_error(char **arguments, int argc)
{
	if (argc == 2)
		error_exit_ac2(arguments);
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	clear_free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*previous;

	if (!*stack)
		return ;
	current = *stack;
	previous = *stack;
	while (current != NULL)
	{
		current = current->next;
		free(previous);
		previous = current;
	}
	*stack = NULL;
}
