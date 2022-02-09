/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 00:43:27 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/09 21:08:14 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	ft_lstsizebis(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	rra(t_stack **stack, t_data *data)
{
	t_stack	*last;
	t_stack	*cur;
	int		i;

	ft_addmove(&(data->move), "rra");
	cur = *stack;
	i = -1;
	while (++i < ft_lstsizebis(*stack) - 2)
		cur = cur->next;
	last = cur->next;
	cur->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rrb(t_stack **stack, t_data *data)
{
	t_stack	*last;
	t_stack	*cur;
	int		i;

	ft_addmove(&(data->move), "rrb");
	cur = *stack;
	i = -1;
	while (++i < ft_lstsizebis(*stack) - 2)
		cur = cur->next;
	last = cur->next;
	cur->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rrr(t_stack **stacka, t_stack **stackb, t_data *data)
{
	rra(stacka, data);
	rrb(stackb, data);
}
