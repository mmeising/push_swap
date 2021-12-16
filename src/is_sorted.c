/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 22:12:25 by mmeising          #+#    #+#             */
/*   Updated: 2021/12/13 01:39:12 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	checks if stack_a is sorted and stack_b is empty. if only checking stack_a,
 *	argument stack_b should be given as NULL
 */
int	is_sorted(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->next)
	{
		if (stack_a->val > stack_a->next->val)
			return (0);
		stack_a = stack_a->next;
	}
	if (stack_b == NULL)
		return (1);
	return (0);
}
