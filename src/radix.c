/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:58:04 by mmeising          #+#    #+#             */
/*   Updated: 2021/12/15 00:29:02 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	size_t	count_vals_a;
	size_t	count_bits;
	size_t	i;

	i = 0;
	count_bits = get_max_bits(*stack_a);
	while (i < count_bits)
	{
		count_vals_a = count_a(*stack_a);
		while (count_vals_a)
		{
			if ((*stack_a)->val & (1 << i))
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			count_vals_a--;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}
