/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 00:41:43 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/10 15:44:28 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pa(t_stack **stackb, t_stack **stacka, t_data *data)
{
	t_stack	*cur;

	ft_addmove(&(data->move), "pa", data);
	cur = *stackb;
	*stackb = cur->next;
	cur->next = *stacka;
	*stacka = cur;
}

void	pb(t_stack **stackb, t_stack **stacka, t_data *data)
{
	t_stack	*cur;

	ft_addmove(&(data->move), "pb", data);
	cur = *stacka;
	*stacka = cur->next;
	cur->next = *stackb;
	*stackb = cur;
}
