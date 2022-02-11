/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:22:02 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/11 05:06:45 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

char	*ft_strjoinbis(char *s1, char *s2)
{
	char	*str;
	size_t	lens1;
	size_t	lens2;

	if ((!s1 && s2) || (!s1 || !s2))
		free(s2);
	if ((!s2 && s1) || (!s1 || !s2))
		free(s1);
	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, lens1);
	ft_memcpy(str + lens1, s2, lens2);
	str[lens1 + lens2] = '\0';
	free(s1);
	free(s2);
	return (str);
}

int	ft_movetonb(char *str)
{
	if (!ft_strcmp(str, "pa"))
		return (1);
	else if (!ft_strcmp(str, "pb"))
		return (2);
	else if (!ft_strcmp(str, "ra"))
		return (3);
	else if (!ft_strcmp(str, "rb"))
		return (4);
	else if (!ft_strcmp(str, "rra"))
		return (5);
	else if (!ft_strcmp(str, "rrb"))
		return (6);
	else if (!ft_strcmp(str, "sa"))
		return (7);
	else if (!ft_strcmp(str, "sb"))
		return (8);
	return (0);
}

char	*ft_nbtomove(int move)
{
	if (move == 1)
		return ("pa");
	else if (move == 2)
		return ("pb");
	else if (move == 3)
		return ("ra");
	else if (move == 4)
		return ("rb");
	else if (move == 5)
		return ("rra");
	else if (move == 6)
		return ("rrb");
	else if (move == 7)
		return ("sa");
	else if (move == 8)
		return ("sb");
	return (0);
}

int	ft_precheck(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_strchr("-+0123456789 ", argv[i][j]))
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
