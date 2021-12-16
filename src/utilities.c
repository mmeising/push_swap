/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:44:17 by mmeising          #+#    #+#             */
/*   Updated: 2021/12/15 00:35:50 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	takes input string, converts it to integer. If input string is either
 *	bigger than INT_MAX or smaller than INT_MIN, exits with error
 */
int	ps_atoi(const char *str)
{
	long long int	nb;
	int				i;
	int				sign;

	nb = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] == '\0')
		exit(error(EXIT_INPUT_NOT_INT));
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (sign * nb < -2147483648 || sign * nb > 2147483647
		|| !((str[i] >= '0' && str[i] <= '9') || str[i] == '\0'))
		exit(error(EXIT_INPUT_NOT_INT));
	return (sign * nb);
}

size_t	count_pos(t_stack *stack_a, unsigned int val)
{
	size_t	count_pos;

	count_pos = 0;
	while (stack_a && stack_a->val != val)
	{
		stack_a = stack_a->next;
		count_pos++;
	}
	if (stack_a->val != val)
		count_pos = -1;
	return (count_pos);
}

void	rotate_to_top(t_stack **stack_a, unsigned int val)
{
	size_t	count;
	size_t	val_pos;

	count = count_a(*stack_a);
	val_pos = count_pos(*stack_a, val);
	if (val_pos <= count / 2)
	{
		while ((*stack_a)->val != val)
			ra(stack_a);
	}
	else if (val_pos == (size_t)-1)
		exit(error(EXIT_COUNT_POS_FAIL));
	else
	{
		while ((*stack_a)->val != val)
			rra(stack_a);
	}
}

int	is_in_range_of_a(t_stack *stack_a, unsigned int val)
{
	unsigned int	min;
	unsigned int	max;

	min = get_min_val(stack_a);
	max = get_max_val(stack_a);
	if (val > min && val < max)
		return (1);
	else
		return (0);
}

size_t	get_max_bits(t_stack *stack_a)
{
	unsigned int	max_val;
	size_t			bits;

	max_val = get_max_val(stack_a);
	bits = 0;
	while (max_val)
	{
		max_val /= 2;
		bits++;
	}
	return (bits);
}
