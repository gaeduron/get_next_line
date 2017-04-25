/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduron <duron.benjamin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 16:54:22 by bduron            #+#    #+#             */
/*   Updated: 2017/04/25 20:27:43 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "error\n", 6);
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
		printf("%s || i -> %d\n", line, i);
	close(fd);
	return (0);
}
