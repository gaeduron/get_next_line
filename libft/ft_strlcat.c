/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:04:11 by gduron            #+#    #+#             */
/*   Updated: 2017/04/12 17:01:14 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	val;

	val = ft_strlen(dst) + ft_strlen((char *)src);
	if (ft_strlen(dst) > size)
		return (size + ft_strlen((char *)src));
	while (size && *dst)
	{
		size--;
		dst++;
	}
	if (!size)
		return (val);
	while (size > 1)
	{
		*dst++ = *src++;
		size--;
	}
	*dst = '\0';
	return (val);
}
