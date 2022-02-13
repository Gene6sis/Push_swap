/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:51:44 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/13 16:14:41 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	ra(t_stack **stack, t_data *data)
{
	t_stack	*last;
	t_stack	*first;

	if (ft_lstsizebis(*stack) < 2)
		return ;
	first = *stack;
	last = ft_lstlastbis(*stack);
	if (!first || !last)
		ft_end("Impossible move", data, 4);
	last->next = first;
	*stack = first->next;
	first->next = NULL;
}

void	rb(t_stack **stack, t_data *data)
{
	t_stack	*last;
	t_stack	*first;

	if (ft_lstsizebis(*stack) < 2)
		return ;
	first = *stack;
	last = ft_lstlastbis(*stack);
	if (!first || !last)
		ft_end("Impossible move", data, 4);
	last->next = first;
	*stack = first->next;
	first->next = NULL;
}

void	rr(t_stack **stacka, t_stack **stackb, t_data *data)
{
	ra(stacka, data);
	rb(stackb, data);
}
