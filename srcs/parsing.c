/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:55:20 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/11 03:26:52 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_preparestack(t_data *data)
{
	char	*str;
	int		i;

	i = 1;
	str = ft_strdup("");
	while (i < data->argc)
	{
		str = ft_strjoinbis(ft_strjoinbis(str, ft_strdup(" ")),
				ft_strdup(data->argv[i++]));
		if (!str)
			ft_end("Malloc error, your split failed", data, 0);
	}
	data->split = ft_split(str, ' ');
	free(str);
}

void	ft_create_stack(t_data *data)
{
	int		i;
	t_stack	*new;

	i = -1;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		ft_end("Stack creation failed", data, 1);
	data->stacka = new;
	while (++i < data->nb_number)
	{
		if (i < data->nb_number - 1)
		{
			new->next = (t_stack *)malloc(sizeof(t_stack));
			if (!new->next)
				ft_end("Stack creation failed", data, 2);
		}
		new->number = ft_atoi(data->split[i]);
		if (i == (data->nb_number - 1))
			new->next = NULL;
		else
			new = new->next;
	}
}

void	init_move(t_data *data)
{
	data->move = (t_move *)malloc(sizeof(t_move));
	if (!data->move)
		ft_end("Move ceation failed", data, 2);
	data->move->next = NULL;
	data->move->action = 0;
}

int	ft_initstack(t_data	*data)
{
	int		i;

	ft_preparestack(data);
	if (!data->split)
		ft_end("Malloc error, your split failed", data, 1);
	if (!ft_validarg(data->argc, data->split) || ft_dupnb(data->split))
		ft_end("Invalid argument", data, 1);
	data->nb_number = 0;
	while (data->split[data->nb_number])
		data->nb_number++;
	ft_create_stack(data);
	init_move(data);
	ft_median(data);
	i = -1;
	while (data->split[++i])
		free(data->split[i]);
	free(data->split);
	data->stackb = NULL;
	return (1);
}

int	ft_parsing(t_data *data, char **argv, int argc)
{
	data->argv = argv;
	data->argc = argc;
	if (!ft_precheck(data->argc, data->argv))
		return (0);
	if (!ft_initstack(data))
		return (0);
	return (1);
}
