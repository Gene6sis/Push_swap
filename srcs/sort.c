/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:48:15 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/10 14:16:32 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sort(t_data *data)
{
	if (data->nb_number == 2)
		return (ra(&(data->stacka), data));
	else if (data->nb_number == 3)
		ft_sortthree(data);
	else if (data->nb_number >= 4 && data->nb_number <= 5)
		ft_sortfive(data);
	else if (data->nb_number > 5)
	{
		ft_sortfirst(data);
		ft_sortsecond(data);
		ft_sortthird(data);
	}
}
