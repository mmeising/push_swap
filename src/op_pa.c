/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 00:56:33 by coder             #+#    #+#             */
/*   Updated: 2021/12/14 22:25:49 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	pushes top element of stack_b to top of stack_a
 */
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_b)
	{
		temp = NULL;
		if ((*stack_b)->next)
			temp = (*stack_b)->next;
		lstadd_front(stack_a, *stack_b);
		*stack_b = temp;
		printf("pa\n");
	}
	else
		ft_putstr_fd("FAIL! tried pa but failed\n", 2);
}
