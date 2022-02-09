/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 00:42:46 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/09 21:08:40 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

t_stack	*ft_lstlastbis(t_stack *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	ra(t_stack **stack, t_data *data)
{
	t_stack	*last;
	t_stack	*first;

	ft_addmove(&(data->move), "ra");
	first = *stack;
	last = ft_lstlastbis(*stack);
	last->next = first;
	*stack = first->next;
	first->next = NULL;
}

void	rb(t_stack **stack, t_data *data)
{
	t_stack	*last;
	t_stack	*first;

	ft_addmove(&(data->move), "rb");
	first = *stack;
	last = ft_lstlastbis(*stack);
	last->next = first;
	*stack = first->next;
	first->next = NULL;
}

void	rr(t_stack **stacka, t_stack **stackb, t_data *data)
{
	ra(stacka, data);
	rb(stackb, data);
}
