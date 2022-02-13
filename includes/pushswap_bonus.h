/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:04:55 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/13 15:05:59 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_BONUS_H
# define PUSHSWAP_BONUS_H

# include "../ft_printf/ft_printf.h"
# include "../gnl/get_next_line.h"
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
	char			**move;
	int				nb_move;
}				t_data;

/*	|||||||||||||| 	 ERROR || FREE	 |||||||||||	*/

int		ft_end(char *message, t_data *data, int error);

/*	||||||||||||||| 	UTILS	 |||||||||||||||	*/

t_stack	*ft_lstlastbis(t_stack *lst);
int		ft_lstsizebis(t_stack *lst);
int		ft_atolcheck(char *str, long max, long min);

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

void	sa(t_stack **stack, t_data *data);
void	sb(t_stack **stack, t_data *data);
void	ss(t_stack **stacka, t_stack **stackb, t_data *data);
void	ra(t_stack **stack, t_data *data);
void	rb(t_stack **stack, t_data *data);
void	rr(t_stack **stacka, t_stack **stackb, t_data *data);
void	rra(t_stack **stack, t_data *data);
void	rrb(t_stack **stack, t_data *data);
void	rrr(t_stack **stacka, t_stack **stackb, t_data *data);
void	pa(t_stack **stackb, t_stack **stacka, t_data *data);
void	pb(t_stack **stackb, t_stack **stacka, t_data *data);

/*	||||||||||||||| 	CHECKER	 |||||||||||||||	*/

void	ft_checkarg(t_data *data);
void	ft_createstack(t_data *data);
int		ft_addstock(char *str, t_data *data);
int		ft_checkmove(t_data *data);
void	ft_standard(t_data *data);

#endif
