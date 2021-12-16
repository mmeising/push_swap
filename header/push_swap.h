/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:34:39 by mmeising          #+#    #+#             */
/*   Updated: 2021/12/16 03:42:18 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define EXIT_INPUT_NOT_INT 1//input is > MAX_INT or < INT_MIN
# define EXIT_MALLOC_FAILED 2//ptr after malloc is NULL
# define EXIT_INPUT_NULL_CHAR 3//input string "" invalid
# define EXIT_DOUBLE_INT_USAGE 4//input integer was used before
# define EXIT_SORTED 5//list is sorted
# define EXIT_COUNT_POS_FAIL 6//count_pos returned -1

/*
 *	val_orig is the original value set as argument to the program call.
 *	val is that number ordered starting from 1 so that:
 *	7 -3 12 9 -10 (val_orig) becomes
 *	3 2 5 4 1 (val)
 */
typedef struct s_stack
{
	int				val_orig;
	unsigned int	val;
	struct s_stack	*next;
}	t_stack;

/*	UTILITIES=================================================================*/

int				ps_atoi(const char *str);
int				error(int err_code);
size_t			count_a(t_stack *stack_a);
size_t			count_pos(t_stack *stack_a, unsigned int val);
void			rotate_to_top(t_stack **stack_a, unsigned int val);
unsigned int	get_min_val(t_stack *stack_a);
unsigned int	get_max_val(t_stack *stack_a);
int				is_in_range_of_a(t_stack *stack_a, unsigned int val);
unsigned int	get_bigger_b(t_stack *stack_a, t_stack *stack_b);
size_t			get_max_bits(t_stack *stack_a);
void			free_list(t_stack **stack_a);

/*	LIST STUFF================================================================*/

t_stack			*lstnew(int val_orig);
t_stack			*lstlast(t_stack *lst);
void			lstadd_back(t_stack **lst, t_stack *new);
void			lstadd_front(t_stack **lst, t_stack *new);

/*	OPERATIONS================================================================*/

void			pb(t_stack **stack_a, t_stack **stack_b);
void			pa(t_stack **stack_a, t_stack **stack_b);
void			ra(t_stack **stack_a);
void			rra(t_stack **stack_a);
void			sa(t_stack **stack_a);

/*	STUFF=====================================================================*/

void			assign_ordered_values(t_stack *stack_a);
int				is_sorted(t_stack *stack_a, t_stack *stack_b);
void			sort_small(t_stack **stack_a, t_stack **stack_b, size_t count);
void			radix_sort(t_stack **stack_a, t_stack **stack_b);

#endif