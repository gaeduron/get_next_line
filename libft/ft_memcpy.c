/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 11:24:31 by gduron            #+#    #+#             */
/*   Updated: 2017/04/12 16:54:35 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dst_tmp;
	unsigned char *src_tmp;

	dst_tmp = dst;
	src_tmp = (unsigned char*)src;
	while (n--)
		dst_tmp[n] = src_tmp[n];
	return (dst);
}
