/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:52:34 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/10 15:47:02 by adben-mc         ###   ########.fr       */
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
	cur->action = action;
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
		if (next && ((ft_str(cur->action, "rra") && ft_str(next->action, "rrb"))
				|| (ft_str(cur->action, "rrb") && ft_str(next->action, "rra"))))
		{
			cur = cur->next;
			ft_printf("rrr\n");
		}
		else if (next && ((ft_str(cur->action, "ra")
					&& ft_str(next->action, "rb"))
				|| (ft_str(cur->action, "rb") && ft_str(next->action, "ra"))))
		{
			cur = cur->next;
			ft_printf("rr\n");
		}
		else if (!ft_str(cur->action, " "))
			ft_printf("%s\n", cur->action);
		cur = cur->next;
	}
}

void	ft_printstacks(t_stack	*stack);

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

/*
// void	ft_printstacks(t_stack	*stack)
// {
// 	t_stack	*cur;

// 	cur = stack;
// 	while (cur)
// 	{
// 		if (cur == stack)
// 			ft_printf("%d	<---o\n", cur->number);
// 		else
// 			ft_printf("%d\n", cur->number);
// 		cur = cur->next;
// 	}
// }
*/