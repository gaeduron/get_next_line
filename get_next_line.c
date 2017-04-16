/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:05:06 by gduron            #+#    #+#             */
/*   Updated: 2017/04/16 23:26:25 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int 	find_next_newline(t_gnl *gnl)
{
	int		i;

	i = 0;
	while (gnl->str[gnl->index + i] && gnl->str[gnl->index + i] == '\n')
		i++;
}

int		waiting_line(t_gnl *gnl, char **line)
{
	if (!find_next_newline(gnl))
		return(0);
	
	*line = next_line(gnl->str);
	return (1)
}







int		get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl;

	if (fd < 0 || line == 0 || *line == 0 || BUFF_SIZE < 1)
		return (-1);
	if (gnl == 0)
		init_gnl(gnl);
	if (waiting_line(gnl, line))
		return (1);
    if (!(buff = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
        return (0);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		gnl.str = read_loop(gnl.str, buff, ret);
		if (gnl.str == 0)
		{
			free(buff);
			return (-1);
		}
		
	}
	free(gnl->str);
	free(buff);
	return (ret == 0 ? 0 : -1);

}
