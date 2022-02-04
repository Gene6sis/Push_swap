/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:04:55 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/04 12:15:20 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack {
	size_t			position;
	int				number;
	void			*next;
	struct s_list	*previous;
}				t_stack;

typedef struct s_data {
	char			**argv;
	int				argc;
	t_stack			*stacka;
	t_stack			*stackb;
	int				nb_number;
	int				nb_ina;
	int				nb_inb;
}				t_data;

#endif