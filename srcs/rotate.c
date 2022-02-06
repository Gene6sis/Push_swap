/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 00:42:46 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/06 06:47:11 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static t_stack	*ft_lstlastbis(t_stack *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}


void	ra(t_stack **stack)
{
	t_stack *last;
	t_stack *first;

	first = *stack;
	last = ft_lstlastbis(*stack);
	if (!first || !last)
	{
		ft_printf("ra on NULL\n");
		return ;
	}
	last->next = first;
	*stack = first->next;
	first->next = NULL;
}

void	rb(t_stack **stack)
{
	t_stack *last;
	t_stack *first;

	first = *stack;
	last = ft_lstlastbis(*stack);
	if (!first || !last)
	{
		ft_printf("rb on NULL\n");
		return ;
	}
	last->next = first;
	*stack = first->next;
	first->next = NULL;
}

void	rr(t_stack **stacka, t_stack **stackb)
{
	ra(stacka);
	rb(stackb);
}
