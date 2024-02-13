/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:39:20 by plang             #+#    #+#             */
/*   Updated: 2024/02/09 15:49:28 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */
/*                                 Librarys                                   */
/* ************************************************************************** */

# include "libft/libft.h"
# include "limits.h"

/* ************************************************************************** */
/*                                  Structs                                   */
/* ************************************************************************** */

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}	t_stack;

/* ************************************************************************** */
/*                            Push swap functions                             */
/* ************************************************************************** */

int		ft_lstsize_stack(t_stack **stack);
int		is_it_sorted(t_stack *stack);
int		main(int argc, char **argv);

/* ************************************************************************** */
/*                          Check input functions                             */
/* ************************************************************************** */

long	ft_atol_stack(const char *str);
int		check_duplicate(long compare, char **arguments, int i);
int		check_digit_n_sign(char *argument);
void	check_input(int argc, char **argv);

/* ************************************************************************** */
/*                           Make stack functions                             */
/* ************************************************************************** */

t_stack	*find_bottom(t_stack *stack_a);
t_stack	**ft_add_to_bottom(t_stack **stack_a, int nbr);
t_stack	*get_min_data(t_stack **stack);
void	index_to_node(t_stack **stack_a);
void	init_stack(t_stack **stack_a, int argc, char **argv);

/* ************************************************************************** */
/*                          Sort stack functions                              */
/* ************************************************************************** */

int		fetch_min_n_push(t_stack *stack_a);
int		get_bit_limit(int biggest_index);
void	radix_small(t_stack **stack_a, t_stack **stack_b, int bit_limit, int i);
void	radix_big(t_stack **stack_a, t_stack **stack_b, int bit_limit, int i);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);

/* ************************************************************************** */
/*                           Short sort functions                             */
/* ************************************************************************** */

void	sort_2(t_stack **stack_a);
void	sort_3(t_stack **stack_a);
void	sort_4(t_stack **stack_a, t_stack **stack_b);
void	sort_5(t_stack **stack_a, t_stack **stack_b, int steps);
void	short_sort(t_stack **stack_a, t_stack **stack_b);

/* ************************************************************************** */
/*                            A actions functions                             */
/* ************************************************************************** */

void	do_sa(t_stack **stack);
void	do_ra(t_stack **stack);
void	do_rra(t_stack **stack);
void	do_pb(t_stack **stack_a, t_stack **stack_b);

/* ************************************************************************** */
/*                            B actions functions                             */
/* ************************************************************************** */

void	do_sb(t_stack **stack);
void	do_rb(t_stack **stack);
void	do_rrb(t_stack **stack);
void	do_pa(t_stack **stack_a, t_stack **stack_b);

/* ************************************************************************** */
/*                             Actions functions                              */
/* ************************************************************************** */

void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	push(t_stack **dest_stack, t_stack **src_stack);
int		get_steps(t_stack *stack_a);

/* ************************************************************************** */
/*                              Error functions                               */
/* ************************************************************************** */

void	error_exit_ac2(char **array);
void	free_split(char **array);
void	ft_error(char **arguments, int argc);
void	clear_free_stack(t_stack **stack);

#endif
