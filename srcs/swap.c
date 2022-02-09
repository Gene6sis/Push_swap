/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 00:38:09 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/09 21:17:21 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	sa(t_stack **stack, t_data *data)
{
	t_stack	*cur;
	int		temp;

	ft_addmove(&(data->move), "sa");
	cur = *stack;
	cur = cur->next;
	temp = (*stack)->number;
	(*stack)->number = cur->number;
	cur->number = temp;
}

void	sb(t_stack **stack, t_data *data)
{
	t_stack	*cur;
	int		temp;

	ft_addmove(&(data->move), "sb");
	cur = *stack;
	cur = cur->next;
	temp = (*stack)->number;
	(*stack)->number = cur->number;
	cur->number = temp;
}

void	ss(t_stack **stacka, t_stack **stackb, t_data *data)
{
	sa(stacka, data);
	sb(stackb, data);
}
