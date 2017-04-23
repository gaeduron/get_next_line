/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:05:06 by gduron            #+#    #+#             */
/*   Updated: 2017/04/23 23:50:10 by bduron           ###   ########.fr       */
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

int		waiting_line(t_gnl *g, char **line, char *buff)
{
	long	nl;
	
	if (buff[0] == 0)
	{
		!(buff = ft_strjoin(g->s, buff)) ? free(buff) : 0;
		if (buff == 0)
		    return (-1);
		g->s = ft_strdup(buff);	
	}
	if (!(nl = ft_strchr(&(g->s[g->i]) , '\n') - g->s) && !ft_strlen(&(g->s[g->i])))
		return (0);
	nl < 0 ? (*line = ft_strdup(&(g->s[g->i]))) : \
		(*line = ft_strsub(g->s, g->i, nl - g->i));
	nl > 0 ? (g->i = (nl + 1)) : 0;
	//g->s[g->i] == '\n' ? g->i-- : 0;
	return (1);
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
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0 && \
		(!ft_strchr(buff, '\n') ? 1 : (buff[ret] = 0)))
	{
		buff[ret] = '\0';
		!(buff = ft_strjoin(g->s, buff)) ? free(buff) : 0;
		if (buff == 0)
			return (-1);
		g->s = ft_strdup(buff);
	}
	ft_strchr(buff, '\n') ? 0 : (buff[0] = 0) ;
	if (waiting_line(g, line, buff))
		return (1);
	free(g->s);
	free(buff);
	return (ret == 0 ? 0 : -1);
}
