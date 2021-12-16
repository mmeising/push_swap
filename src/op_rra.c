/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 00:57:05 by coder             #+#    #+#             */
/*   Updated: 2021/12/10 23:24:17 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	rotates all elements of stack_a down by one, last element becomes first
 */
void	rra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*last;

	last = lstlast(*stack_a);
	temp = *stack_a;
	while (temp->next != last)
		temp = temp->next;
	temp->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	printf("rra\n");
}
