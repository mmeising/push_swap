/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 23:09:47 by mmeising          #+#    #+#             */
/*   Updated: 2021/12/14 22:25:36 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	pushes top element of stack_a to top of stack_b
 */
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_a)
	{
		temp = NULL;
		if ((*stack_a)->next)
			temp = (*stack_a)->next;
		lstadd_front(stack_b, *stack_a);
		*stack_a = temp;
		printf("pb\n");
	}
	else
		ft_putstr_fd("FAIL! tried pb but failed\n", 2);
}
