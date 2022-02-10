/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortthird.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:22:02 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/10 14:16:00 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sortthird(t_data	*data)
{
	t_stack	*cur;
	int		min;

	cur = data->stacka;
	min = cur->number;
	while (cur)
	{
		if (min > cur->number)
			min = cur->number;
		cur = cur->next;
	}
	cur = data->stacka;
	while (data->stacka->number != min)
	{
		if (ft_scrolldown_worth(data->stacka, min))
			rra(&(data->stacka), data);
		else
			ra(&(data->stacka), data);
	}
}
