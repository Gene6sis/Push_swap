/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:48:15 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/08 01:16:58 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

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
			rra(&(data->stacka));
		else
			ra(&(data->stacka));
	}
}

void	ft_sort(t_data *data)
{
	ft_sortfirst(data);
	ft_sortsecond(data);
	ft_sortthird(data);
}
