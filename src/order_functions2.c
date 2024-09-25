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