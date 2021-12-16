/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 03:38:23 by mmeising          #+#    #+#             */
/*   Updated: 2021/12/16 03:42:30 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_stack **stack_a)
{
	t_stack	*temp;

	temp = NULL;
	while (*stack_a)
	{
		temp = (*stack_a)->next;
		free(*stack_a);
		*stack_a = temp;
	}
}
