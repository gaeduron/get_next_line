/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:05:06 by gduron            #+#    #+#             */
/*   Updated: 2017/04/24 20:49:31 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*add_or_find_gnl(t_gnl *head, int fd)
{
	t_gnl	*last;

	last = head;
	while (last && last->next)
	{
		if (last->fd == fd)
			return (last);
		last = last->next;
	}
	if (last && last->fd == fd)
		return (last);
	gnl = (t_gnl*)malloc(sizeof(t_gnl));
	gnl->s = ft_strdup("");
	gnl->tmp = 0;
	gnl->next = 0;
	gnl->fd = fd;
	head ? gnl->head = head : gnl->head = gnl;
	last ? last->next = gnl : 0;
	return (gnl);
}

t_gnl		*init_or_finish_gnl(t_gnl *gnl, int fd, int init)
{	
	if (init)
		return (add_or_find_gnl(gnl ? gnl->head : 0));
	if (gnl)
	free(gnl);
	gnl = 0;	
	return (gnl);
}

int		waiting_line(t_gnl *g, char **line, char *nl)
{
	free(nl);
	nl = ft_strchr(g->s, '\n');
	nl ? *line = ft_strsub(g->s, 0, nl - g->s) : (*line = ft_strdup(g->s));
	nl ? (g->s = ft_memmove(g->s, nl + 1, ft_strlen(nl))) : 0;
	if (g->s[0] == 0 && !nl)
	{
		!nl ? free(g->s) : 0;
		!nl ? g->s = 0 : 0;
		return (0);
	}
	!nl ? free(g->s) : 0;
	!nl ? g->s = 0 : 0;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*g;
	char		*buff;
	long		ret;

	if (fd < 0 || !line || BUFF_SIZE < 1 || \
			!(buff = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	g = init_gnl(g ,fd) : 0;
	while (((ret = read(fd, buff, BUFF_SIZE)) > 0 || g->s) && ret != -1)
	{
		buff[ret] = '\0';
		!(g->tmp = ft_strjoin(g->s, buff)) ? free(buff) : 0;
		if (g->tmp == 0)
			return (-1);
		ft_memdel((void**)&(g->s));
		g->s = ft_strdup(g->tmp);
		free(g->tmp);
		if (ft_strchr(g->s, '\n') || !ret)
			return (waiting_line(g, line, buff));
	}
	ret == -1 ? free(g->s) : 0;
	g = init_gnl(g);
	free(buff);
	return (ret == 0 ? 0 : -1);
}
