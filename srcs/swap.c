/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 00:38:09 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/06 06:44:40 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	sa(t_stack **stack)
{
	t_stack	*cur;
	int		temp;

	cur = *stack;
	if (!*stack || !(cur->next))
	{
		ft_printf("Move sa on null\n");
		return ;
	}
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
	if (!*stack || !(cur->next))
	{
		ft_printf("Move sb on null\n");
		return ;
	}
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
