/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 15:57:40 by gduron            #+#    #+#             */
/*   Updated: 2017/04/23 23:49:55 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include "libft/includes/libft.h"

int				get_next_line(const int fd, char **line);

typedef struct	s_gnl
{
	long		i;
	char		*s;
}				t_gnl;
# define BUFF_SIZE 1
#endif
