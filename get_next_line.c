/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:05:06 by gduron            #+#    #+#             */
/*   Updated: 2017/04/23 00:46:36 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	init_gnl(t_gnl *gnl)
{
	gnl = (t_gnl*)malloc(sizeof(t_gnl));
	gnl->str_start = ft_strdup("");
	return (gnl);
}

int		waiting_line(t_gnl *gnl, char **line)
{
	char	*next_nl;
	
	if (!(next_nl = ft_strchr(gnl->str, '\n')) && !ft_strlen(gnl->str))
		return (0);
	!next_nl ? *line = ft_strdup(gnl->str) : \
		*line = ft_strsub(gnl->str, 0, next_nl - gnl->str - 1);
	gnl->str = next_nl + 1;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl;
	long			ret;

	if (fd < 0 || !line || *line == 0 || BUFF_SIZE < 1 || \
		!(buff = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	gnl == 0 ? gnl = init_gnl(gnl) : 0;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0 && !ft_strchr(gnl->str, '\n'))
	{
		buff[ret] = '\0';
		!(gnl->str = ft_strjoin(gnl->str, buff)) ? free(buff) : 0 ;
		if (gnl->str == 0)
			return (-1);
	}
	if (waiting_line(gnl, line))
		return (1);
	free(gnl->str_start);
	free(buff);
	return (ret == 0 ? 0 : -1);
}
