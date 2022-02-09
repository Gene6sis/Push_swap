/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:21:59 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/09 21:29:08 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

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

int	ft_scrolldown_worth(t_stack	*stack, int nb)
{
	t_stack	*cur;
	int		i;

	i = 0;
	cur = stack;
	while (cur)
	{
		if (nb == cur->number)
		{
			if ((ft_lstsizebis(stack) / 2 + 1) > i)
				return (0);
			else
				return (1);
		}
		i++;
		cur = cur->next;
	}
	return (0);
}
