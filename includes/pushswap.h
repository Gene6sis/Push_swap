/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:04:55 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/06 23:01:57 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack {
	int				number;
	void			*next;
}				t_stack;

typedef struct s_data {
	char			**argv;
	int				argc;
	t_stack			*stacka;
	t_stack			*stackb;
	int				nb_number;
	int				nb_ina;
	int				nb_inb;
	int				median;
	int				max_nb;
}				t_data;

/*	||||||||||||||| 	UTILS	 |||||||||||||||	*/

void	ft_printstacks(t_stack	*stack);

/*	||||||||||||||| 	PARSE	 |||||||||||||||	*/

int		ft_dupnb(char	**argv);
int		ft_have_nb(char *str);
int		ft_validarg(int argc, char **argv);
char	*ft_strjoinbis(char *s1, char *s2);
char	**ft_preparestack(t_data	*data);
t_stack	*ft_create_stack(char **split, int count);
int		ft_initstack(t_data	*data);
int		ft_parsing(t_data *data, char **argv, int argc);

/*	||||||||||||||| 	MOVES	 |||||||||||||||	*/

void	pa(t_stack **stackb, t_stack **stacka);
void	pb(t_stack **stackb, t_stack **stacka);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stacka, t_stack **stackb);
void	ss(t_stack **stacka, t_stack **stackb);
void	sa(t_stack **stack);
void	sb(t_stack **stack);

/*	||||||||||||||| 	SORT	 |||||||||||||||	*/

void	ft_median(t_data *data);
void	ft_sort(t_data *data);

#endif