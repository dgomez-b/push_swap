/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_error_functions.c                            :+:      :+:    :+:   */
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

void	missing_stack_error(void)
{
	ft_putendl_fd("Error -> Missing stack", 1);
	exit (0);
}

void	node_creation_error(t_int_stack *stack)
{
	stack_clear(stack);
	ft_putendl_fd("Error -> Stack node creation failed", 1);
	exit (0);
}

void	empty_stack_error(void)
{
	ft_putendl_fd("Error -> The stack is already empty", 1);
	exit (0);
}
