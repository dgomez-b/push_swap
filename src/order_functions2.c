/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 00:00:00 by dgomez-b          #+#    #+#             */
/*   Updated: 2024/09/15 00:00:00 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	missing_stack_error(void);

t_bool	is_ordered(t_int_stack stack)
{
	unsigned int	last_index;

	while (stack->index != 1)
		stack = stack->next;
	last_index = 1;
	stack = stack->next;
	while (stack->index - 1 == last_index)
	{
		last_index = stack->index;
		stack = stack->next;
	}
	if (stack->index - 1 != last_index && stack->index != 1)
		return (FALSE);
	return (TRUE);
}

static void	small_order2(t_int_stack *stack)
{
	if (((*stack)->index + 1 == (*stack)->next->index)
		|| ((*stack)->index == 4 && (*stack)->next->index == 2))
	{
		move_silent_swap(stack);
		ft_putendl_fd("sb", 1);
	}
	if ((*stack)->index == 3 && (*stack)->next->index == 2)
		move_reverse_rotate((void *)0, stack);
	else if ((*stack)->index == 2 && (*stack)->next->index == 4)
		move_rotate((void *)0, stack);
}

static void	small_order_3(t_int_stack *stack_a, t_int_stack *stack_b)
{
	if ((*stack_a)->index == 1)
		move_rotate(stack_a, (void *)0);
	move_push(stack_a, stack_b, FALSE);
	move_push(stack_a, stack_b, FALSE);
	move_push(stack_a, stack_b, FALSE);
	move_reverse_rotate(stack_a, (void *)0);
}

void	small_order1(t_int_stack *stack_a, t_int_stack *stack_b)
{
	unsigned int	counter;
	unsigned int	length;

	length = stack_length(*stack_a);
	counter = length - 2;
	while (counter-- > 0)
	{
		if (((*stack_a)->index == 1 && (*stack_a)->next->index == length)
			|| ((*stack_a)->index == length && (*stack_a)->next->index == 1))
			move_reverse_rotate(stack_a, (void *)0);
		else if (((*stack_a)->index != 1 && (*stack_a)->index == length)
			|| ((*stack_a)->next->index != 1
			&& (*stack_a)->next->index!= length))
			move_rotate(stack_a, (void *)0);
		move_push(stack_a, stack_b, TRUE);
	}
	if (stack_length(*stack_b) != 2)
		small_order2(stack_b);
	else
		if ((*stack_b)->index < (*stack_b)->next->index)
			move_rotate((void *)0, stack_b);
	small_order_3(stack_a, stack_b);
}