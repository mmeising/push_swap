/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:17:24 by mmeising          #+#    #+#             */
/*   Updated: 2021/12/15 00:35:59 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	creates new list element with content set to val_orig
 */
t_stack	*lstnew(int val_orig)
{
	t_stack	*ele;

	ele = (t_stack *)malloc(sizeof(*ele));
	if (ele == NULL)
		return (NULL);
	ele->val_orig = val_orig;
	ele->val = 0;
	ele->next = NULL;
	return (ele);
}

/*
 *	returns pointer to last list element
 */
t_stack	*lstlast(t_stack *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*
 *	adds argument "t_stack *new" to back of list. If list is NULL, makes element
 *	new the new start of the list
 */
void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*back;

	back = NULL;
	if (*lst != NULL)
	{
		back = lstlast(*lst);
		back->next = new;
	}
	else
		*lst = new;
}

/*
 *	adds element new to front of list and makes it the new start
 */
void	lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}
