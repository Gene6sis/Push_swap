/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 00:41:43 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/06 23:49:31 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	pa(t_stack **stackb, t_stack **stacka)
{
	t_stack	*cur;

	// ft_printf("pa\n");
	cur = *stackb;
	if (!*stackb)
	{
		ft_printf("Move pa error, stackb is null\n");
		return ;
	}
	*stackb = cur->next;
	cur->next = *stacka;
	*stacka = cur;
}

void	pb(t_stack **stackb, t_stack **stacka)
{
	t_stack	*cur;

	// ft_printf("pb\n");
	cur = *stacka;
	if (!*stacka)
	{
		ft_printf("Move pb error, stacka is null\n");
		return ;
	}
	*stacka = cur->next;
	cur->next = *stackb;
	*stackb = cur;
}