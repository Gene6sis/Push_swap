/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfirst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:07:09 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/08 04:45:41 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static void	ft_checkmedian(t_data *data)
{
	if (data->stackb->number < data->median && ft_lstsizebis(data->stackb) > 1)
		rb(&(data->stackb));
}

void ft_sortfirst(t_data *data)
{
	while (data->stacka->next)
	{
		if (data->stacka->number == data->max_nb)
			ra(&(data->stacka));
		pb(&(data->stackb), &(data->stacka));
		ft_checkmedian(data);
	}
}