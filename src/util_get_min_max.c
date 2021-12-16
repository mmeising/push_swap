/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_get_min_max.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:53:15 by mmeising          #+#    #+#             */
/*   Updated: 2021/12/14 22:30:35 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	get_min_val(t_stack *stack_a)
{
	unsigned int	min;

	min = stack_a->val;
	while (stack_a)
	{
		if (min > stack_a->val)
			min = stack_a->val;
		stack_a = stack_a->next;
	}
	return (min);
}

unsigned int	get_max_val(t_stack *stack_a)
{
	unsigned int	max;

	max = stack_a->val;
	while (stack_a)
	{
		if (max < stack_a->val)
			max = stack_a->val;
		stack_a = stack_a->next;
	}
	return (max);
}

/*
 *	returns the smallest value inside stack_a that's still larger than
 *	the value on top of stack_b
 */
unsigned int	get_bigger_b(t_stack *stack_a, t_stack *stack_b)
{
	unsigned int	small;

	small = get_max_val(stack_a);
	while (stack_a)
	{
		if (stack_a->val < small && stack_a->val > stack_b->val)
			small = stack_a->val;
		stack_a = stack_a->next;
	}
	return (small);
}
