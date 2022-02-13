/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:22:28 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/13 16:06:10 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	ft_move(t_data *data, size_t i)
{
	while (data->move[i])
	{
		if (!ft_strcmp(data->move[i], "sa"))
			sa(&(data->stacka), data);
		if (!ft_strcmp(data->move[i], "sb"))
			sb(&(data->stackb), data);
		if (!ft_strcmp(data->move[i], "ss"))
			ss(&(data->stacka), &(data->stackb), data);
		if (!ft_strcmp(data->move[i], "ra"))
			ra(&(data->stacka), data);
		if (!ft_strcmp(data->move[i], "rb"))
			rb(&(data->stackb), data);
		if (!ft_strcmp(data->move[i], "rr"))
			rr(&(data->stacka), &(data->stackb), data);
		if (!ft_strcmp(data->move[i], "rra"))
			rra(&(data->stacka), data);
		if (!ft_strcmp(data->move[i], "rrb"))
			rrb(&(data->stackb), data);
		if (!ft_strcmp(data->move[i], "rrr"))
			rrr(&(data->stacka), &(data->stackb), data);
		if (!ft_strcmp(data->move[i], "pa"))
			pa(&(data->stackb), &(data->stacka), data);
		if (!ft_strcmp(data->move[i++], "pb"))
			pb(&(data->stackb), &(data->stacka), data);
	}
}

void	ft_printstacks(t_stack	*stack)
{
	t_stack	*cur;

	cur = stack;
	while (cur)
	{
		if (cur == stack)
			ft_printf("%d	<---o\n", cur->number);
		else if (cur)
			ft_printf("%d\n", cur->number);
		cur = cur->next;
	}
}

void	ft_sorted(t_data *data)
{
	t_stack	*cur;
	t_stack	*next;

	if (ft_lstsizebis(data->stackb) > 0)
		ft_end("Stack B not empty", data, 4);
	cur = data->stacka;
	while (cur)
	{
		next = cur->next;
		if (next && cur->number > next->number)
			ft_end("Stack A isn't sorted", data, 4);
		cur = next;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (0);
	data.argc = argc;
	data.argv = argv;
	ft_checkarg(&data);
	ft_createstack(&data);
	ft_standard(&data);
	ft_move(&data, 0);
	ft_sorted(&data);
	ft_end(NULL, &data, 4);
	return (0);
}
