/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduron <duron.benjamin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 16:54:22 by bduron            #+#    #+#             */
/*   Updated: 2017/04/24 19:09:48 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
//	static char *str;
//	char 		*str_n;
//
//	str == 0 ? str = ft_strnew() : 0;
//	!str ? free(str) : 0;
//	str_n = strchr(str, '\n');
//	printf("%p\n", str);
//	printf("%p\n", str_n);
//	printf("%ld", str_n - str);
	int		fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
   		write(1, "error\n", 6);
		return (0);
	}
	while (get_next_line(fd, &line) > 0)
		printf("%s\n", line);
	close(fd);

	return (0);
}
