/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_error_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 00:00:00 by dgomez-b          #+#    #+#             */
/*   Updated: 2024/09/15 00:00:00 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>

void	invalid_arg_amount_error(void)
{
	ft_putendl_fd("Error -> There should be at least 1 valid argument", 1);
	exit (0);
}

void	invalid_arg_error(t_int_stack *stacks)
{
	if (stacks[0])
		stack_clear(&stacks[0]);
	if (stacks[1])
		stack_clear(&stacks[1]);
	ft_putendl_fd("Error -> Values should be integer", 1);
	exit (0);
}

void	duplicated_value_error(t_int_stack *stack_a, t_int_stack *stack_b)
{
	if (stack_a && *stack_a)
		stack_clear(stack_a);
	if (stack_b && *stack_b)
		stack_clear(stack_b);
	ft_putendl_fd("Error -> Duplicate values are forbidden", 1);
	exit (0);
}
