/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 00:00:00 by dgomez-b          #+#    #+#             */
/*   Updated: 2024/09/15 00:00:00 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	move_push(t_int_stack *stack_a, t_int_stack *stack_b, t_bool to_stack_b)
{
	unsigned int	index;

	if (!stack_a || !stack_b || (!*stack_a && to_stack_b)
		|| (!*stack_b && !to_stack_b))
		return ;
	if (to_stack_b)
	{
		index = (*stack_a)->index;
		stack_push(stack_b, stack_pop(stack_a), index);
		ft_putendl_fd("pb", 1);
	}
	else
	{
		index = (*stack_b)->index;
		stack_push(stack_a, stack_pop(stack_b), index);
		ft_putendl_fd("pa", 1);
	}
}

void	move_rotate(t_int_stack *stack_a, t_int_stack *stack_b)
{
	if ((!stack_a || !*stack_a) && (!stack_b || !*stack_b))
		return ;
	else if (!stack_a || !*stack_a)
	{
		*stack_b = (*stack_b)->next;
		ft_putendl_fd("rb", 1);
	}
	else if (!stack_b || !*stack_b)
	{
		*stack_a = (*stack_a)->next;
		ft_putendl_fd("ra", 1);
	}
	else
	{
		*stack_a = (*stack_a)->next;
		*stack_b = (*stack_b)->next;
		ft_putendl_fd("rr", 1);
	}
}

void	move_reverse_rotate(t_int_stack *stack_a, t_int_stack *stack_b)
{
	if ((!stack_a || !*stack_a) && (!stack_b || !*stack_b))
		return ;
	else if (!stack_a || !*stack_a)
	{
		*stack_b = (*stack_b)->previous;
		ft_putendl_fd("rrb", 1);
	}
	else if (!stack_b || !*stack_b)
	{
		*stack_a = (*stack_a)->previous;
		ft_putendl_fd("rra", 1);
	}
	else
	{
		*stack_a = (*stack_a)->previous;
		*stack_b = (*stack_b)->previous;
		ft_putendl_fd("rrr", 1);
	}
}

void	move_silent_swap(t_int_stack *stack)
{
	int	aux_value;
	int	aux_index;

	aux_index = (*stack)->index;
	aux_value = stack_pop(stack);
	*stack = (*stack)->next;
	stack_push(stack, aux_value, aux_index);
	*stack = (*stack)->previous;
}
