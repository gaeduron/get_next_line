/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 15:57:40 by gduron            #+#    #+#             */
/*   Updated: 2017/04/23 00:46:38 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

int				get_next_line(const int fd, char **line);

typedef struct	s_gnl
{
	char		*str;
	char		*str_start;
}				t_gnl;
# define BUFF_SIZE 32
#endif
