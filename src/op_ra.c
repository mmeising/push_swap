/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 00:56:39 by coder             #+#    #+#             */
/*   Updated: 2021/12/10 23:24:04 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	rotates all elements of stack_a up by one, first element becomes last
 */
void	ra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*last;

	last = lstlast(*stack_a);
	last->next = *stack_a;
	temp = (*stack_a)->next;
	(*stack_a)->next = NULL;
	*stack_a = temp;
	printf("ra\n");
}
