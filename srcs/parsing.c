/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:55:20 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/10 10:40:29 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

char	**ft_preparestack(t_data *data)
{
	char	*str;
	int		i;
	char	**split;

	i = 1;
	str = ft_strdup("");
	while (i < data->argc)
	{
		str = ft_strjoinbis(ft_strjoinbis(str, ft_strdup(" ")),
				ft_strdup(data->argv[i++]));
		if (!str)
			return (NULL);
	}
	split = ft_split(str, ' ');
	free(str);
	return (split);
}

t_stack	*ft_create_stack(char **split, int count)
{
	int		i;
	t_stack	*new;
	t_stack	*first;

	i = -1;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		exit(1);
	first = new;
	while (++i < count)
	{
		if (i < count - 1)
		{
			new->next = (t_stack *)malloc(sizeof(t_stack));
			if (!new->next)
				exit(1);
		}
		new->number = ft_atoi(split[i]);
		if (i == (count - 1))
			new->next = NULL;
		else
			new = new->next;
	}
	return (first);
}

t_move	*init_move(void)
{
	t_move	*first;

	first = (t_move *)malloc(sizeof(t_move));
	if (!first)
		exit(1);
	first->next = NULL;
	first->action = " ";
	return (first);
}

int	ft_initstack(t_data	*data)
{
	char	**split;
	int		i;

	split = ft_preparestack(data);
	if (!split)
		return (0);
	if (!ft_validarg(data->argc, split) || ft_dupnb(split))
		return (0);
	data->nb_number = 0;
	while (split[data->nb_number])
		data->nb_number++;
	data->stacka = ft_create_stack(split, data->nb_number);
	data->move = init_move();
	data->argv = split;
	ft_median(data);
	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	data->stackb = NULL;
	return (1);
}

int	ft_parsing(t_data *data, char **argv, int argc)
{
	data->argv = argv;
	data->argc = argc;
	if (!ft_validarg(data->argc, data->argv))
		return (0);
	if (!ft_initstack(data))
		return (0);
	return (1);
}
