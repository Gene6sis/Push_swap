/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:52:34 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/08 21:16:49 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int ft_dupnb(char **argv)
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

int	ft_have_nb(char *str)
{
	size_t	i;
	int		number;

	number = 0;
	i = 0;
	while (str[i])
	{
		if (ft_strchr("0123456789", str[i]))
			number = 1;
		i++;
	}
	return (number);
}

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
			if (!ft_strchr("-+0123456789 ", argv[i][j]) || !ft_have_nb(argv[i]))
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

char	*ft_strjoinbis(char *s1, char *s2)
{
	char	*str;
	size_t	lens1;
	size_t	lens2;

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

void	ft_printstacks(t_stack	*stack)
{
	t_stack *cur;

	cur = stack;
	while (cur)
	{
		if (cur == stack)
			ft_printf("%d	<---o\n", cur->number);
		else 
			ft_printf("%d\n", cur->number);
		cur = cur->next;
	}
}

void	ft_free(t_data *data)
{
	t_stack	*cur;
	t_stack	*next;

	cur = data->stacka;		
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;		
	}
	free(cur);
}

int ft_issort(t_stack *stack)
{
	t_stack	*cur;
	t_stack	*next;

	cur = stack;		
	while (cur)
	{
		next = cur->next;
		if (next && cur->number > next->number)
			return (0);
		cur = next;		
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!ft_parsing(&data, argv, argc))
		return (1);
	if (!ft_issort(data.stacka))
		ft_sort(&data);
	ft_free(&data);
}
