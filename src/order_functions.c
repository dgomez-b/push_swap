/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 00:00:00 by dgomez-b          #+#    #+#             */
/*   Updated: 2024/09/15 00:00:00 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static int	simple_sqrt(int number)
{
	int	i;

	if (number < 4)
		return (1);
	i = 2;
	while (i * i < number)
		i++;
	if (i * i > number)
	{
		if ((i * i - number) < ((i - 1) * (i - 1) + (-number)))
			return (i);
	}
	return (i - 1);
}

void	fill_indexes(t_int_stack stack)
{
	unsigned int	index;
	unsigned int	length;
	t_int_stack		min_value;
	t_int_stack		cur_value;

	if (!stack)
		return ;
	index = 0;
	length = stack_length(stack);
	while (index++ < length)
	{
		min_value = stack;
		cur_value = stack->next;
		while (cur_value->next != stack)
		{
			if ((cur_value->value < min_value->value && cur_value->index == 0)
				|| min_value->index != 0)
				min_value = cur_value;
			cur_value = cur_value->next;
		}
		if ((cur_value->value < min_value->value && cur_value->index == 0)
			|| min_value->index != 0)
				min_value = cur_value;
		min_value->index = index;
	}
}

void	k_sort(t_int_stack *stack_a, t_int_stack *stack_b)
{
	unsigned int	length;
	unsigned int	counter;
	int				range;

	if (!stack_a || !*stack_a)
		return ;
	length = stack_length(*stack_a);
	counter = 0;
	range = simple_sqrt(length) * 1.4;
	while (*stack_a)
	{
		if ((*stack_a)->index <= counter)
		{
			move_push(stack_a, stack_b, TRUE);
			move_rotate((void *)0, stack_b);
			counter++;
		}
		else if ((*stack_a)->index <= counter + range)
		{
			move_push(stack_a, stack_b, TRUE);
			counter++;
		}
		else
			move_rotate(stack_a, (void *)0);
	}
}

static unsigned int	max_index_rotations(t_int_stack stack, unsigned int index)
{
	unsigned int	counter;

	counter = 0;
	while (stack && stack->index != index)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}

void	k_sort2(t_int_stack *stack_a, t_int_stack *stack_b)
{
	unsigned int	rb_count;
	unsigned int	rrb_count;
	unsigned int	length;

	length = stack_length(*stack_b);
	while (length > 1)
	{
		rb_count = max_index_rotations(*stack_b, length);
		rrb_count = (length + 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while ((*stack_b)->index != length)
				move_rotate((void *)0, stack_b);
			move_push(stack_a, stack_b, FALSE);
			length--;
		}
		else
		{
			while ((*stack_b)->index != length)
				move_reverse_rotate((void *)0, stack_b);
			move_push(stack_a, stack_b, FALSE);
			length--;
		}
	}
	move_push(stack_a, stack_b, FALSE);
}