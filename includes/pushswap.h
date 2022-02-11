/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:04:55 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/11 05:07:04 by adben-mc         ###   ########.fr       */
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

typedef struct s_move {
	int				action;
	void			*next;
}				t_move;

typedef struct s_data {
	char			**argv;
	int				argc;
	t_stack			*stacka;
	t_move			*move;
	t_stack			*stackb;
	int				nb_number;
	int				median;
	int				max_nb;
	char			**split;
}				t_data;

/*	|||||||||||||| 	 ERROR || FREE	 |||||||||||	*/

int		ft_end(char *message, t_data *data, int error);

/*	||||||||||||||| 	UTILS	 |||||||||||||||	*/

void	ft_printstacks(t_stack	*stack);
char	*ft_strjoinbis(char *s1, char *s2);
void	ft_printstacks(t_stack	*stack);
t_stack	*ft_lstlastbis(t_stack *lst);
int		ft_getnb(t_stack *stack, int pos);
int		ft_lstsizebis(t_stack *lst);
int		ft_movetonb(char *str);
char	*ft_nbtomove(int move);

/*	||||||||||||||| 	PARSE	 |||||||||||||||	*/

int		ft_dupnb(char	**argv);
int		ft_have_nb(char *str);
int		ft_validarg(int argc, char **argv);
char	*ft_strjoinbis(char *s1, char *s2);
void	ft_preparestack(t_data *data);
void	ft_create_stack(t_data *data);
int		ft_initstack(t_data	*data);
int		ft_parsing(t_data *data, char **argv, int argc);

/*	||||||||||||||| 	MOVES	 |||||||||||||||	*/

void	pa(t_stack **stackb, t_stack **stacka, t_data *data);
void	pb(t_stack **stackb, t_stack **stacka, t_data *data);
void	rra(t_stack **stack, t_data *data);
void	rrb(t_stack **stack, t_data *data);
void	rrr(t_stack **stacka, t_stack **stackb, t_data *data);
void	ra(t_stack **stack, t_data *data);
void	rb(t_stack **stack, t_data *data);
void	rr(t_stack **stacka, t_stack **stackb, t_data *data);
void	ss(t_stack **stacka, t_stack **stackb, t_data *data);
void	sa(t_stack **stack, t_data *data);
void	sb(t_stack **stack, t_data *data);

/*	||||||||||||||| 	SORT	 |||||||||||||||	*/

void	ft_median(t_data *data);
void	ft_sort(t_data *data);

void	ft_sortfirst(t_data *data);
void	ft_sortsecond(t_data *data);
void	ft_sortthird(t_data	*data);

void	ft_sortthree(t_data	*data);
void	ft_sortfive(t_data *data);
void	ft_pushmintob(t_data *data);

void	ft_addmove(t_move **move, char *action, t_data *data);
int		ft_scrolldown_worth(t_stack	*stack, int nb);
int		ft_precheck(int argc, char **argv);

#endif
