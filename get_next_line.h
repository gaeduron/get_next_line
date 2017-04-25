/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 15:57:40 by gduron            #+#    #+#             */
/*   Updated: 2017/04/25 20:28:02 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/includes/libft.h"

int					get_next_line(const int fd, char **line);

typedef struct		s_gnl
{
	char			*tmp;
	char			*s;
	int				fd;
	struct s_gnl	*head;
	struct s_gnl	*next;
	struct s_gnl	*last;
}					t_gnl;
# define BUFF_SIZE 173
#endif
