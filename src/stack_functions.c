/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.h                                  :+:      :+:    :+:   */
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

void	missing_stack_error(void);
void	node_creation_error(t_int_stack *stack);
void	empty_stack_error(void);

/// @brief Clears a stack
/// @param stack The stack to be cleared
void	stack_clear(t_int_stack *stack)
{
	t_int_stack	current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current->previous != current)
	{
		current->next->previous = current->previous;
		current = current->next;
		free(*stack);
		*stack = current;
	}
	free(*stack);
}

/// @brief Inserts a value into a stack
/// @param stack The stack where the integer will be inserted
/// @param value The value to be inserted
void	stack_push(t_int_stack *stack, int value, unsigned int index)
{
	t_int_stack	new_element;

	if (!stack)
		missing_stack_error();
	new_element = malloc(sizeof(t_int_stack_node));
	if (!new_element)
		node_creation_error(stack);
	new_element->index = index;
	new_element->value = value;
	new_element->previous = new_element;
	new_element->next = new_element;
	if (*stack)
	{
		new_element->previous = (*stack)->previous;
		new_element->next = *stack;
		new_element->previous->next = new_element;
		new_element->next->previous = new_element;
	}
	*stack = new_element;
}

/// @brief Takes the first value from the stack
/// @param stack The stack where the value will be taken
/// @return The first value of the stack
int	stack_pop(t_int_stack *stack)
{
	int			value_removed;
	t_int_stack	next_element;
	t_int_stack	previous_element;

	if (!stack)
		missing_stack_error();
	if (!*stack)
		empty_stack_error();
	value_removed = (*stack)->value;
	previous_element = (*stack)->previous;
	next_element = (*stack)->next;
	if (*stack == next_element)
	{
		free(*stack);
		*stack = (void *)0;
	}
	else
	{
		free(*stack);
		previous_element->next = next_element;
		next_element->previous = previous_element;
		*stack = next_element;
	}
	return (value_removed);
}

/// @brief Gets the length of the stack
/// @param stack_element The stack
/// @return The stack length
unsigned int	stack_length(t_int_stack stack_element)
{
	t_int_stack		first_element;
	int	counter;

	if (!stack_element)
		return (0);
	first_element = stack_element;
	counter = 1;
	while (first_element != stack_element->next)
	{
		stack_element = stack_element->next;
		counter++;
	}
	return (counter);
}
