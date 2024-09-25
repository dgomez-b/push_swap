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
// 		ft_putnbr_fd(stack_pop(&stacks[1]), 1);
// 		ft_putendl_fd("", 1);
// 	}
// }

static void	small_order2(t_int_stack *stack)
{
	if (((*stack)->index - 1 == (*stack)->next->index)
		|| ((*stack)->index == 1 && (*stack)->next->index == 3))
	{
		move_silent_swap(stack);
		ft_putendl_fd("sa", 1);
	}
	if ((*stack)->index == 2 && (*stack)->next->index == 3)
		move_reverse_rotate(stack, (void *)0);
	else if ((*stack)->index == 3 && (*stack)->next->index == 1)
		move_rotate(stack, (void *)0);
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
	else if (stack_length(stacks[0]) > 5)
	{
		k_sort(&stacks[0], &stacks[1]);
		k_sort2(&stacks[0], &stacks[1]);
	}
	else if (stack_length(stacks[0]) == 3)
		small_order2(&stacks[0]);
	else
		small_order1(&stacks[0], &stacks[1]);
	// print_stacks(stacks);
	stack_clear(&stacks[0]);
	return (0);
}
