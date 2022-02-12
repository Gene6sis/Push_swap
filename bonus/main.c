/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:22:28 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/12 19:42:17 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	ft_checkarg(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 1;
	data->nb_number = 0;
	while (data->argv[i])
	{
		j = 0;
		while (data->argv[i][j])
		{
			if (!ft_strchr("-+0123456789", (char)data->argv[i][j]))
				ft_end("Invalid argument", data, 0);		
			j++;
		}
		i++;
		data->nb_number++;
	}
}

void	ft_createstack(t_data *data)
{
	int		i;
	t_stack	*new;

	i = -1;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		ft_end("Stack creation failed", data, 0);
	data->stacka = new;
	while (++i < data->nb_number)
	{
		if (i < data->nb_number - 1)
		{
			new->next = (t_stack *)malloc(sizeof(t_stack));
			if (!new->next)
				ft_end("Stack creation failed", data, 1);
		}
		new->number = ft_atoi(data->argv[i + 1]);
		if (i == (data->nb_number - 1))
			new->next = NULL;
		else
			new = new->next;
	}
}

static int	ft_addstock(char *str, t_data *data)
{
	char	**newmap;
	size_t	i;

	i = 0;
	newmap = malloc(sizeof(char *) * (data->nb_move + 1));
	if (!newmap)
		ft_end("Newmap creation failed", data, 3);
	while (data->move[i])
	{
		newmap[i] = data->move[i];
		i++;
	}
	newmap[i++] = str;
	newmap[i] = NULL;
	i = 0;
	free(data->move);
	data->move = newmap;
	return (0);
}

int	ft_checkmove(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->move[i])
	{
		if ((!ft_strcmp(data->move[i], "sa")
			|| !ft_strcmp(data->move[i], "sb")
			|| !ft_strcmp(data->move[i], "ss")
			|| !ft_strcmp(data->move[i], "ra")
			|| !ft_strcmp(data->move[i], "rb")
			|| !ft_strcmp(data->move[i], "rr")
			|| !ft_strcmp(data->move[i], "rrr")
			|| !ft_strcmp(data->move[i], "rra")
			|| !ft_strcmp(data->move[i], "rrb")
			|| !ft_strcmp(data->move[i], "pa")
			|| !ft_strcmp(data->move[i], "pb"))
			&& (ft_strlen(data->move[i]) == 2
			|| ft_strlen(data->move[i]) == 3))
			return (1);
		i++;
	}
	return (0);
}

void	ft_standard(t_data *data)
{
	char	*new_line;
	
	data->move = malloc(sizeof(char *));
	if (!data->move)
		ft_end("Map allocation failed", data, 1);
	data->move[0] = NULL;
	data->nb_move = 0;
	new_line = get_next_line(0);
	if (!new_line)
		ft_end("No movement entered", data, 2);
	while (new_line)
	{
		data->nb_move++;
		ft_addstock(new_line, data);
		new_line = get_next_line(0);
	}
	close(0);
	if (!ft_checkmove(data))
		ft_end("Unknow move", data, 3);
}

void	ft_move(t_data *data)
{
		
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.argc = argc;
	data.argv = argv;
	ft_checkarg(&data);
	ft_createstack(&data);
	ft_standard(&data);
	for(int i = 0; data.move[i]; i++)
	{
		ft_printf("Ligne [%d] : %s\n", i, data.move[i]);
	}
	ft_end(NULL, &data, 3);
	ft_move(&data);
	// ft_sorted(&data);
	return (0);
}