/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:21:59 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/10 14:16:00 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_median(t_data	*data)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	data->max_nb = ft_atoi(data->argv[i]);
	while (data->argv[i])
	{
		j = i + 1;
		while (data->argv[j])
		{
			if (ft_atoi(data->argv[i]) > ft_atoi(data->argv[j]))
			{
				temp = data->argv[i];
				data->argv[i] = data->argv[j];
				data->argv[j] = temp;
			}
			if (ft_atoi(data->argv[j]) > data->max_nb)
				data->max_nb = ft_atoi(data->argv[j]);
			j++;
		}
		i++;
	}
	data->median = ft_atoi(data->argv[(i) / 2]);
}
