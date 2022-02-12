/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:19:33 by adben-mc          #+#    #+#             */
/*   Updated: 2022/02/12 18:21:08 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 32

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_strchrgnl(const char *s, int c);
char	*ft_strjoingnl(char *s1, char *s2);
size_t	ft_strlengnl(const char *s);
void	*ft_memcpygnl(void *dst, const void *src, size_t n);
char	*ft_fill_str(int fd, char *str);
char	*find_line(char *save);

#endif