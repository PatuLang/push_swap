/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:49:21 by plang             #+#    #+#             */
/*   Updated: 2024/08/05 14:50:03 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atol_stack(const char *str)
{
	int		negative;
	long	result;

	negative = 1;
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 45)
	{
		negative = -1;
		str++;
	}
	else if (*str == 43)
		str++;
	while (*str >= 48 && *str <= 57)
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * negative);
}

int	check_duplicate(long compare, char **arguments, int i)
{
	while (arguments[i + 1] != '\0')
	{
		if (compare == ft_atol_stack(arguments[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int	check_digit_n_sign(char *argument)
{
	int	i;

	i = 0;
	if (ft_strlen(argument) > 11)
		return (1);
	if (argument[0] == '-' || argument[0] == '+')
		i++;
	if (argument[i] == '\0')
		return (1);
	while (argument[i])
	{
		if (argument[i] < '0' || argument[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	check_input(int argc, char **argv)
{
	int		i;
	long	arg_holder;
	char	**arguments;

	i = 0;
	if (argc == 2)
		arguments = ft_split(argv[1], ' ');
	else
		arguments = argv + 1;
	if (!arguments[0])
		error_exit_ac2(arguments);
	while (arguments[i])
	{
		arg_holder = ft_atol_stack(arguments[i]);
		if (check_digit_n_sign(arguments[i]))
			ft_error(arguments, argc);
		if (check_duplicate(arg_holder, arguments, i))
			ft_error(arguments, argc);
		if (arg_holder > INT_MAX || arg_holder < INT_MIN)
			ft_error(arguments, argc);
		i++;
	}
	if (argc == 2)
		free_split(arguments);
}
