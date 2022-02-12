/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:51:44 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/12 19:39:08 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	pa(t_stack **stackb, t_stack **stacka)
{
	t_stack	*cur;

	cur = *stackb;
	*stackb = cur->next;
	cur->next = *stacka;
	*stacka = cur;
}

void	pb(t_stack **stackb, t_stack **stacka)
{
	t_stack	*cur;

	cur = *stacka;
	*stacka = cur->next;
	cur->next = *stackb;
	*stackb = cur;
}

void	sa(t_stack **stack)
{
	t_stack	*cur;
	int		temp;

	cur = *stack;
	cur = cur->next;
	temp = (*stack)->number;
	(*stack)->number = cur->number;
	cur->number = temp;
}

void	sb(t_stack **stack)
{
	t_stack	*cur;
	int		temp;

	cur = *stack;
	cur = cur->next;
	temp = (*stack)->number;
	(*stack)->number = cur->number;
	cur->number = temp;
}

void	ss(t_stack **stacka, t_stack **stackb)
{
	sa(stacka);
	sb(stackb);
}
