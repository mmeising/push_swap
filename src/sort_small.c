/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 23:04:27 by mmeising          #+#    #+#             */
/*   Updated: 2021/12/14 22:29:56 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	hardcoded sorting for 3 numbers in stack_a, handling the 5 possible setups
 */
static void	sort_3(t_stack **stack_a)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;

	a = (*stack_a)->val;
	b = (*stack_a)->next->val;
	c = (*stack_a)->next->next->val;
	if ((a < c && c < b) || (b < a && a < c) || (c < b && b < a))
		sa(stack_a);
	if ((a < c && c < b) || (b < c && c < a))
		ra(stack_a);
	if ((c < b && b < a) || (c < a && a < b))
		rra(stack_a);
}

/*
 *	pushes the top value of stack_b to the right position in stack_a
 */
static void	insert_one(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b)
	{
		if (is_in_range_of_a(*stack_a, (*stack_b)->val))
			rotate_to_top(stack_a, get_bigger_b(*stack_a, *stack_b));
		else
			rotate_to_top(stack_a, get_min_val(*stack_a));
		pa(stack_a, stack_b);
	}
}

/*
 *	sorts for up to 5 input numbers
 */
void	sort_small(t_stack **stack_a, t_stack **stack_b, size_t count)
{
	if (count == 2)
		sa(stack_a);
	else if (count == 3)
		sort_3(stack_a);
	else if (count == 4)
	{
		pb(stack_a, stack_b);
		sort_3(stack_a);
		insert_one(stack_a, stack_b);
		rotate_to_top(stack_a, 0);
	}
	else if (count == 5)
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		sort_3(stack_a);
		insert_one(stack_a, stack_b);
		insert_one(stack_a, stack_b);
		rotate_to_top(stack_a, 0);
	}
}
