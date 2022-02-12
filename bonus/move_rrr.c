/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:51:44 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/12 23:31:14 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	rra(t_stack **stack, t_data *data)
{
	t_stack	*last;
	t_stack	*cur;
	int		i;

	if (!*stack)
		ft_end("Impossible move", data, 4);
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

	if (!*stack)
		ft_end("Impossible move", data, 4);
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
