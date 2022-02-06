/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 00:43:27 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/06 23:10:31 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static int	ft_lstsizebis(t_stack *lst)
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


void	rra(t_stack **stack)
{
	t_stack	*last;
	t_stack	*cur;
	int		i;

	ft_printf("rra\n");
	if (!*stack)
	{
		ft_printf("rra on NULL\n");
		return ;
	}
	cur = *stack;
	i = -1;
	while (++i < ft_lstsizebis(*stack) - 1)
		cur = cur->next;
	last = cur->next;
	cur->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rrb(t_stack **stack)
{
	t_stack	*last;
	t_stack	*cur;
	int		i;

	ft_printf("rrb\n");
	if (!*stack)
	{
		ft_printf("rra on NULL\n");
		return ;
	}
	cur = *stack;
	i = -1;
	while (++i < ft_lstsizebis(*stack) - 1)
		cur = cur->next;
	last = cur->next;
	cur->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rrr(t_stack **stack) //soucis
{
	ft_printf("rrr\n");
	rra(stack);
	rrb(stack);
}
