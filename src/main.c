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

static void	ordenation_process(t_int_stack *stack_a, t_int_stack *stack_b)
{
	if (is_ordered(*stack_a))
		while ((*stack_a)->index != 1)
			move_rotate(stack_a, (void *)0);
	else if (stack_length(*stack_a) != 5)
	{
		k_sort(stack_a, stack_b);
		k_sort2(stack_a, stack_b);
	}
	else
	{
		small_order1(stack_a, stack_b);
		small_order2(stack_a, stack_b);
		if ((*stack_a)->index == 2)
			move_reverse_rotate(stack_a, (void *)0);
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
	check_duplicated_arguments(&stacks[0], &stacks[1]);
	fill_indexes(stacks[0]);
	ordenation_process(&stacks[0], &stacks[1]);
	stack_clear(&stacks[0]);
	return (0);
}
