/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:48:15 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/06 23:12:06 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static void	ft_checkfirst(t_data *data)
{
	if (data->stackb->number < data->median)
		rb(&(data->stackb));
}

static void ft_sortfirst(t_data *data)
{
	// size_t	i;
	// size_t	j;

	while (data->stacka->next)
	{
		// ft_printf("==========================\nStack A : \n");
		// ft_printstacks(data->stacka);
		// ft_printf("\nStack B : \n\n");
		// ft_printstacks(data->stackb);
		if (data->stacka->number == data->max_nb)
			ra(&(data->stacka));
		pb(&(data->stackb), &(data->stacka));
		ft_checkfirst(data);
	}
}

void	ft_sort(t_data *data)
{
	ft_sortfirst(data);
}
