/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:05:06 by gduron            #+#    #+#             */
/*   Updated: 2017/04/24 19:12:29 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*init_gnl(t_gnl *gnl)
{
	gnl = (t_gnl*)malloc(sizeof(t_gnl));
	gnl->s = ft_strdup("");
	gnl->i = 0;
	return (gnl);
}

int		waiting_line(t_gnl *g, char **line, char *nl)
{
	free(nl);
	nl = ft_strchr(g->s, '\n');
	nl ? *line = ft_strsub(g->s, 0, nl - g->s) : (*line = ft_strdup(g->s));
	nl ? (g->s = ft_memmove(g->s, nl + 1, ft_strlen(nl))) : 0;
	!nl ? free(g->s) : 0;
	!nl ? g->s = 0 : 0;
	return (nl ? 1 : 0);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*g;
	char			*buff;
	long			ret;

	if (fd < 0 || !line || BUFF_SIZE < 1 || \
			!(buff = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	g == 0 ? g = init_gnl(g) : 0;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0 || g->s)
	{
		buff[ret] = '\0';
		!(buff = ft_strjoin(g->s, buff)) ? free(buff) : 0;
		if (buff == 0)
			return (-1);
		ft_memdel((void**)&(g->s));
		g->s = ft_strdup(buff);
		if (ft_strchr(g->s, '\n') || !ret)
			return (waiting_line(g, line, buff));
	}
	free(buff);
	return (ret == 0 ? 0 : -1);
}
