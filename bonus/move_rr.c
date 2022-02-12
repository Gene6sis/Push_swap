/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:51:44 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/12 19:38:46 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	ra(t_stack **stack)
{
	t_stack	*last;
	t_stack	*first;

	first = *stack;
	last = ft_lstlastbis(*stack);
	last->next = first;
	*stack = first->next;
	first->next = NULL;
}

void	rb(t_stack **stack)
{
	t_stack	*last;
	t_stack	*first;

	first = *stack;
	last = ft_lstlastbis(*stack);
	last->next = first;
	*stack = first->next;
	first->next = NULL;
}

void	rr(t_stack **stacka, t_stack **stackb)
{
	ra(stacka);
	rb(stackb);
}
