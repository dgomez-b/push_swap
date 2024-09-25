/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 00:00:00 by dgomez-b          #+#    #+#             */
/*   Updated: 2024/09/15 00:00:00 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	invalid_arg_amount_error(void);

// static void	print_stacks(t_int_stack *stacks)
// {
// 	unsigned int	counter;
// 	unsigned int	length;

// 	length = stack_length(stacks[0]);
// 	ft_putstr_fd("Stack_a length : ", 1);
// 	ft_putnbr_fd(length, 1);
// 	ft_putendl_fd("", 1);
// 	counter = 0;
// 	while (counter++ < length)
// 	{
// 		ft_putchar_fd('(', 1);
// 		ft_putnbr_fd(stacks[0]->index, 1);
// 		ft_putstr_fd(") ", 1);
// 		ft_putnbr_fd(stack_pop(&stacks[0]), 1);
// 		ft_putendl_fd("", 1);
// 	}
// 	length = stack_length(stacks[1]);
// 	ft_putstr_fd("Stack_b length : ", 1);
// 	ft_putnbr_fd(length, 1);
// 	ft_putendl_fd("", 1);
// 	counter = 0;
// 	while (counter++ < length)
// 	{
// 		ft_putchar_fd('(', 1);
// 		ft_putnbr_fd(stacks[1]->index, 1);
// 		ft_putstr_fd(") ", 1);
// 		ft_putnbr_fd(stack_pop(&stacks[1]), 1);
// 		ft_putendl_fd("", 1);
// 	}
// }

static void	small_order3(t_int_stack *stack_a)
{
	if ((*stack_a)->index == 2)
		move_reverse_rotate(stack_a, (void *)0);
}

static void small_order2(t_int_stack *stack_a, t_int_stack *stack_b)
{
	if ((*stack_a)->index == 2 || (*stack_a)->index == 4)
	{
		if ((*stack_b)->index < (*stack_b)->next->index)
			move_rotate((void *)0, stack_b);
		move_push(stack_a, stack_b, TRUE);
		if ((*stack_a)->index == 1 && (*stack_b)->index == 2)
			move_rotate(stack_a, stack_b);
		else if ((*stack_a)->index == 1)
			move_rotate(stack_a, (void *)0);
		else if ((*stack_b)->index == 2)
			move_rotate((void *)0, stack_b);
	}
	else
	{
		if ((*stack_b)->index > (*stack_b)->next->index)
			move_rotate((void *)0, stack_b);
		move_push(stack_a, stack_b, TRUE);
		if ((*stack_a)->index == 1)
			move_reverse_rotate(stack_a, stack_b);
		else
			move_reverse_rotate((void *)0, stack_b);
	}
	move_push(stack_a, stack_b, FALSE);
	move_push(stack_a, stack_b, FALSE);
	move_push(stack_a, stack_b, FALSE);
}

static void	small_order1(t_int_stack *stack_a, t_int_stack *stack_b)
{
	unsigned int	length;
	unsigned int	counter;

	length = stack_length(*stack_a);
	if ((*stack_a)->index == 1 || (*stack_a)->index == length)
		move_rotate(stack_a, (void *)0);
	if ((*stack_a)->index == 1 || (*stack_a)->index == length)
		move_rotate(stack_a, (void *)0);
	counter = 2;
	while (counter-- > 0)
	{
		move_push(stack_a, stack_b, TRUE);
		if (((*stack_a)->index == 1 || (*stack_a)->index == length)
			&& ((*stack_a)->next->index == 1
			|| (*stack_a)->next->index == length))
			move_reverse_rotate(stack_a, (void *)0);
		else if ((*stack_a)->index == 1 || (*stack_a)->index == length)
			move_rotate(stack_a, (void *)0);
	}
}

int	main(int argc, const char **argv)
{
	t_int_stack		stacks[2];

	if (argc <= 1)
		invalid_arg_amount_error();
	stacks[0] = (void *)0;
	stacks[1] = (void *)0;
	while (argc-- > 1)
		push_arg_to_stack(stacks, argv[argc]);
	fill_indexes(stacks[0]);
	if (is_ordered(stacks[0]))
		while (stacks[0]->index != 1)
			move_rotate(&stacks[0], (void *)0);
	else if (stack_length(stacks[0]) != 5)
	{
		k_sort(&stacks[0], &stacks[1]);
		k_sort2(&stacks[0], &stacks[1]);
	}
	else
	{
		small_order1(&stacks[0], &stacks[1]);
		small_order2(&stacks[0], &stacks[1]);
		small_order3(&stacks[0]);
	}
	// print_stacks(stacks);
	return (0);
}
