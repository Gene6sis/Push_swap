/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortsecond.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:10:18 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/07 00:39:58 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	ft_cheapest(t_data	*data, t_stack *stacka, t_stack *stackb)
{
	int cheapest;

	cheapest = stackb->number;
		
}

void ft_sortsecond(t_data *data)
{
	int	cheapest;
	
	cheapest = ft_cheapest(data, data->stacka, data->stackb);
}