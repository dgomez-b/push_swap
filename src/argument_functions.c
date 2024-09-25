/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_functions.c                               :+:      :+:    :+:   */
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
#include <sys/resource.h>

void	invalid_arg_error(t_int_stack *stacks);
void	duplicated_value_error(t_int_stack *stack_a, t_int_stack *stack_b);

static t_bool	arg_is_valid(const char *arg)
{
	unsigned int	counter;

	if (!arg)
		return (TRUE);
	counter = 0;
	while (arg[counter])
	{
		if (!ft_isdigit(arg[counter]) && arg[counter] != '-'
			&& arg[counter] != '+')
			return (FALSE);
		counter++;
	}
	return (TRUE);
}

void	push_arg_to_stack(t_int_stack *stacks, const char *arg)
{
	char	**string_values;
	int		counter;
	int		counter2;

	if (!arg)
		return ;
	string_values = ft_split(arg, ' ');
	counter = 0;
	counter2 = 0;
	while (string_values[counter])
		counter++;
	while (counter-- > 0)
	{
		if (!arg_is_valid(string_values[counter]))
		{
			while (string_values[counter2])
				free(string_values[counter2++]);
			free(string_values);
			invalid_arg_error(stacks);
		}
		stack_push(&stacks[0], ft_atoi(string_values[counter]), 0);
	}
	while (string_values[counter2])
		free(string_values[counter2++]);
	free(string_values);
}

void	check_duplicated_arguments(t_int_stack *stack_a, t_int_stack *stack_b)
{
	t_int_stack		current;
	int				value;
	unsigned int	length;
	unsigned int	length2;

	length = stack_length(*stack_a);
	while (length-- > 0)
	{
		current = *stack_a;
		value = current->value;
		length2 = length;
		while (length2-- > 0)
		{
			current = current->next;
			if (current->value == value)
				duplicated_value_error(stack_a, stack_b);
		}
		*stack_a = (*stack_a)->next;
	}
}
