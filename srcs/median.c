/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:21:59 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/11 04:37:11 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_median(t_data	*data)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	data->max_nb = ft_atoi(data->split[i]);
	while (data->split[i])
	{
		j = i + 1;
		while (data->split[j])
		{
			if (ft_atoi(data->split[i]) > ft_atoi(data->split[j]))
			{
				temp = data->split[i];
				data->split[i] = data->split[j];
				data->split[j] = temp;
			}
			if (ft_atoi(data->split[j]) > data->max_nb)
				data->max_nb = ft_atoi(data->split[j]);
			j++;
		}
		i++;
	}
	data->median = ft_atoi(data->split[(i) / 2]);
}
