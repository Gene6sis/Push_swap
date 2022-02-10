/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:14:42 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/10 15:56:58 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_freestack(t_stack *stack)
{
	t_stack	*cur;
	t_stack	*next;

	cur = stack;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
}

void	ft_freemove(t_move *move)
{
	t_move	*cur;
	t_move	*next;

	cur = move;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
}

void	ft_error(t_data *data, int error)
{
	int	i;

	i = 0;
	if (error >= 1 && error < 3)
	{
		while (data->split[i])
			free(data->split[i++]);
		free(data->split);
	}
	if (error >= 2)
		ft_freestack(data->stacka);
	if (error >= 3)
	{
		ft_freestack(data->stackb);
		ft_freemove(data->move);
	}
}

int	ft_end(char *message, t_data *data, int error)
{
	ft_error(data, error);
	if (message)
	{
		ft_printf("Error : %s\n", message);
		exit(EXIT_FAILURE);
	}
	else
		exit(EXIT_SUCCESS);
}
