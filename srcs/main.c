/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:52:34 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/11 05:06:36 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_issort(t_stack *stack)
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

void	ft_addmove(t_move **move, char *action, t_data *data)
{
	t_move	*cur;

	cur = *move;
	while (cur->next)
		cur = cur->next;
	cur->next = (t_move *)malloc(sizeof(t_move));
	if (!cur->next)
		ft_end("Move creation failed", data, 3);
	cur = cur->next;
	cur->action = ft_movetonb(action);
	cur->next = NULL;
}

void	ft_printres(t_move	*stack)
{
	t_move	*cur;
	t_move	*next;

	cur = stack;
	while (cur)
	{
		next = cur->next;
		if (next && ((cur->action == 5 && next->action == 6)
				|| (cur->action == 6 && next->action == 5)))
		{
			cur = cur->next;
			ft_printf("rrr\n");
		}
		else if (next && ((cur->action == 3 && next->action == 4)
				|| (cur->action == 4 && next->action == 3)))
		{
			cur = cur->next;
			ft_printf("rr\n");
		}
		else if (cur->action != 0)
			ft_printf("%s\n", ft_nbtomove(cur->action));
		cur = cur->next;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!ft_parsing(&data, argv, argc))
		return (1);
	if (!ft_issort(data.stacka))
		ft_sort(&data);
	ft_printres(data.move);
	ft_end(NULL, &data, 10);
}

void	ft_printstacks(t_stack	*stack)
{
	t_stack	*cur;

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
/*
*/