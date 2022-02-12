/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:14:42 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/12 19:19:19 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

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

void	ft_error(t_data *data, int error)
{
	int	i;

	i = 0;
	if (error >= 1)
		ft_freestack(data->stacka);
	if (error == 2)
		free(data->move);
	if (error >= 3)
	{
		while (data->move[i])
			free(data->move[i++]);
		free(data->move);
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
