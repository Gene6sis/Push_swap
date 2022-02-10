/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:57:12 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/10 10:40:45 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	ft_validarg(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
	{
		ft_printf("At least 2 arguments are needed\n");
		return (0);
	}
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_strchr("-+0123456789 ", argv[i][j]) || !ft_have_nb(argv[i])
				|| ft_strlen(argv[i]) == 0)
			{
				ft_printf("Error\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_atolcheck(char *str, long max, long min)
{
	long	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == '\f' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
		result = result * 10 + (long)str[i++] - '0';
	if ((result * sign) > max || (result * sign) < min)
		return (0);
	return (1);
}

int	ft_have_nb(char *str)
{
	size_t	i;
	int		number;

	number = 0;
	i = 0;
	if (!ft_atolcheck(str, 2147483647, -2147483648))
		return (0);
	while (str[i])
	{
		if (ft_strchr("0123456789", str[i]))
			number = 1;
		i++;
	}
	return (number);
}

int	ft_dupnb(char **argv)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (ft_printf("Invalid arguments : Duplicate numbers\n"));
			j++;
		}
		i++;
	}
	return (0);
}
