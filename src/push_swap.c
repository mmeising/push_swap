/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 23:07:42 by mmeising          #+#    #+#             */
/*   Updated: 2021/12/16 03:52:26 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*do_splits(t_stack *stack_a, char **split)
{
	t_stack	*new;
	t_stack	*iter;
	int		i;

	i = 0;
	if (split[i] == NULL)
		exit(error(EXIT_INPUT_NULL_CHAR));
	while (split[i])
	{
		new = lstnew(ps_atoi(split[i]));
		iter = stack_a;
		while (iter)
		{
			if (new->val_orig == iter->val_orig)
				exit(error(EXIT_DOUBLE_INT_USAGE));
			iter = iter->next;
		}
		lstadd_back(&stack_a, new);
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
	return (stack_a);
}

t_stack	*handle_input(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**split;
	int		i;

	i = 1;
	stack_a = NULL;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		stack_a = do_splits(stack_a, split);
		i++;
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	size_t	count;

	if (argc < 2)
		return (0);
	stack_a = handle_input(argc, argv);
	stack_b = NULL;
	assign_ordered_values(stack_a);
	count = count_a(stack_a);
	if (is_sorted(stack_a, stack_b))
		exit(0);
	if (count >= 2 && count <= 5)
		sort_small(&stack_a, &stack_b, count);
	else
		radix_sort(&stack_a, &stack_b);
	free_list(&stack_a);
	exit(0);
	return (0);
}
