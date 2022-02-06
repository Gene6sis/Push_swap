/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 00:42:46 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/06 05:15:10 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	ra(t_stack *stack)
{
	t_stack *cur;
	t_stack *follow;

	cur = stack;
	follow = cur->next;
	if (!cur || !follow)
	{
		ft_printf("ra on NULL\n");
		return ;
	}
	while (follow)
	{
		cur->number = follow->number;
		cur = cur->next;
		follow = follow->next;
	}
	follow->next = stack;
	stack->next = NULL;
}

void	rb(t_stack *stack)
{
	t_stack *cur;
	t_stack *follow;
	t_stack *first;

	cur = stack;
	follow = cur->next;
	first = follow;
	if (!cur || !follow)
	{
		ft_printf("ra on NULL\n");
		return ;
	}
	while (follow)
	{
		cur->number = follow->number;
		cur = cur->next;
		follow = follow->next;
	}
	follow->next = stack;
	stack->next = NULL;
	stack = first;
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
}
