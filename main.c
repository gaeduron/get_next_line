/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduron <duron.benjamin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 16:54:22 by bduron            #+#    #+#             */
/*   Updated: 2017/04/23 00:46:41 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strnew()
{
	char	*str;

	str = strdup("work\n");
	return (str);
}

int	main(int ac, char **av)
{
	static char *str;
	char 		*str_n;

	str == 0 ? str = ft_strnew() : 0;
	!str ? free(str) : 0;
	str_n = strchr(str, '\n');
	printf("%p\n", str);
	printf("%p\n", str_n);
	printf("%ld", str_n - str);
	return (0);
}
