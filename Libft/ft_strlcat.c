/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:46:47 by bvarlamo          #+#    #+#             */
/*   Updated: 2021/07/12 12:44:23 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		t;
	size_t		size;

	size = ft_strlen(dst) + ft_strlen(src);
	t = 0;
	i = 0;
	if (dstsize <= ft_strlen(dst))
	{
		while (src[t])
			t++;
		return (dstsize + t);
	}
	while (dst[i])
		i++;
	while (dstsize > 0 && i < dstsize - 1 && src[t])
	{
		dst[i] = src[t];
		i++;
		t++;
	}
	dst[i] = '\0';
	return (size);
}
