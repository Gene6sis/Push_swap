/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:48:15 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/09 15:49:27 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	ft_getnb(t_stack *stack, int pos)
{
	int		i;
	t_stack	*cur;

	i = 0;
	cur = stack;
	while (i < pos)
	{
		cur = cur->next;
		i++;
	}
	return (cur->number);
}

void	ft_sortthree(t_data	*data)
{
	const int	zero = ft_getnb(data->stacka, 0);
	const int	first = ft_getnb(data->stacka, 1);
	const int	second = ft_getnb(data->stacka, 2);
	

	if (data->nb_number == 2)
		return (ra(&(data->stacka), data));
	if (zero > first &&	first > second && zero > second)
	{
		sa(&(data->stacka), data);
		rra(&(data->stacka), data);
	}
	else if (zero > first && first < second && zero > second)
		ra(&(data->stacka), data);
	else if (zero < first && first > second && zero < second)
	{
		sa(&(data->stacka), data);
		ra(&(data->stacka), data);
	}
	else if (zero > first && first < second && zero < second)
		sa(&(data->stacka), data);
	else if (zero < first && first > second && zero > second)
		rra(&(data->stacka), data);
}

void	ft_sortthird(t_data	*data)
{
	t_stack	*cur;
	int		min;
	
	cur = data->stacka;
	min = cur->number;
	while (cur)
	{
		if (min > cur->number)
			min = cur->number;
		cur = cur->next;
	}
	cur = data->stacka;
	while (data->stacka->number != min)
	{
		if (ft_scrolldown_worth(data->stacka, min))
			rra(&(data->stacka), data);
		else
			ra(&(data->stacka), data);
	}
}

void	ft_pushmintob(t_data *data)
{
	t_stack	*cur;
	int		min;

	cur = data->stacka;
	min = cur->number;
	while (cur)
	{
		if (min > cur->number)
			min = cur->number;
		cur = cur->next;
	}
	while (data->stacka->number != min)
	{
		if (ft_scrolldown_worth(data->stacka, min))
			rra(&(data->stacka), data);
		else
			ra(&(data->stacka), data);
	}
	pb(&(data->stackb), &(data->stacka), data);
}

void	ft_sortfive(t_data *data)
{
	t_stack	*cur;

	if (data->nb_number == 4)
	{
		ft_pushmintob(data);
		ft_sortthree(data);
		pa(&(data->stackb), &(data->stacka), data);
		return ;
	}
	ft_pushmintob(data);
	ft_pushmintob(data);
	ft_sortthree(data);
	cur = data->stackb->next;
	if (data->stackb->number < cur->number)
		sb(&(data->stackb), data);
	pa(&(data->stackb), &(data->stacka), data);
	pa(&(data->stackb), &(data->stacka), data);
}

void	ft_sort(t_data *data)
{
	if (data->nb_number == 2)
		return (ra(&(data->stacka), data));
	else if (data->nb_number == 3)
		ft_sortthree(data);
	else if (data->nb_number >= 4 && data->nb_number <= 5)
	 	ft_sortfive(data);
	else if (data->nb_number > 5)
	{
		ft_sortfirst(data);
		ft_sortsecond(data);
		ft_sortthird(data);
	}
}
