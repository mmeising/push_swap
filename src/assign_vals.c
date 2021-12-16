/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_vals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:56:56 by mmeising          #+#    #+#             */
/*   Updated: 2021/12/05 22:02:00 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	temp is the value to be ordered next, stack_a iterates through the stack
 */
void	assign_ordered_values(t_stack *stack_a)
{
	t_stack			*start;
	t_stack			*temp;

	start = stack_a;
	temp = stack_a;
	while (temp)
	{
		stack_a = start;
		while (stack_a)
		{
			if (temp->val_orig > stack_a->val_orig)
				temp->val++;
			stack_a = stack_a->next;
		}
		temp = temp->next;
	}
}
