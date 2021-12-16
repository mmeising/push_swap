/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:55:50 by mmeising          #+#    #+#             */
/*   Updated: 2021/12/14 22:21:52 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	counts the amount of values inside stack_a
 */
size_t	count_a(t_stack *stack_a)
{
	size_t	i;

	i = 0;
	while (stack_a)
	{
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}
