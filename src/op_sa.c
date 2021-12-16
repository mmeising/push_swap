/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 23:10:36 by mmeising          #+#    #+#             */
/*   Updated: 2021/12/10 23:26:36 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	int				temp_val_orig;
	unsigned int	temp_val;

	temp_val_orig = (*stack_a)->val_orig;
	temp_val = (*stack_a)->val;
	(*stack_a)->val_orig = (*stack_a)->next->val_orig;
	(*stack_a)->val = (*stack_a)->next->val;
	(*stack_a)->next->val_orig = temp_val_orig;
	(*stack_a)->next->val = temp_val;
	printf("sa\n");
}
