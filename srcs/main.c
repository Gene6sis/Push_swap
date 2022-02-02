/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adam <adam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:52:34 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/02 16:03:38 by adam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	ft_validarg(t_data *data)
{
	int	i;
	int	j;
	i = 1;
	while (i < data->argc)
	{
		j = 0;
		while (data->argv[i][j])
		{
			if (!ft_strchr("-+0123456789 ", data->argv[i][j]))
			{
				ft_printf("Invalid character\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_parsing(t_data *data, char **argv, int argc)
{
	data->argv = argv;
	data->argc = argc;
	if (!ft_validarg(data))
		exit(0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (0);
	ft_parsing(&data, argv, argc);
	ft_printf("coucou");
}
