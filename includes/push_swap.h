/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 00:00:00 by dgomez-b          #+#    #+#             */
/*   Updated: 2024/09/15 00:00:00 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/// @brief Buleean value
typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

/// @brief Integer-only stack with pointer to previous and next value
typedef struct s_int_stack_node
{
	unsigned int			index;
	int						value;
	struct s_int_stack_node	*previous;
	struct s_int_stack_node	*next;
}	t_int_stack_node;

typedef t_int_stack_node	*t_int_stack;

// Stack functions
void			stack_clear(t_int_stack *stack);
void			stack_push(t_int_stack *stack, int value, unsigned int index);
int				stack_pop(t_int_stack *stack);
unsigned int	stack_length(t_int_stack stack);

// Argument functions
void			push_arg_to_stack(t_int_stack *stack, const char *arg);
void			check_duplicated_arguments(t_int_stack *stack_a,
					t_int_stack *stack_b);

//Move functions
void			move_push(t_int_stack *stack_a, t_int_stack *stack_b,
					t_bool to_stack_b);
void			move_rotate(t_int_stack *stack_a, t_int_stack *stack_b);
void			move_reverse_rotate(t_int_stack *stack_a, t_int_stack *stack_b);
void			move_silent_swap(t_int_stack *stack);

// Order functions
void			fill_indexes(t_int_stack stack);
void			k_sort(t_int_stack *stack_a, t_int_stack *stack_b);
void			k_sort2(t_int_stack *stack_a, t_int_stack *stack_b);
t_bool			is_ordered(t_int_stack stack);
void			small_order1(t_int_stack *stack_a, t_int_stack *stack_b);
void			small_order2(t_int_stack *stack_a, t_int_stack *stack_b);

#endif
