/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:40:36 by bvarlamo          #+#    #+#             */
/*   Updated: 2021/07/12 12:31:23 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *block, int c, size_t size)
{
	unsigned char	*cblock;

	cblock = block;
	c = (unsigned char)c;
	while (size > 0)
	{
		if (*cblock == c)
		{
			return (cblock);
		}
		else
		{
			size--;
			cblock++;
		}
	}
	return (0);
}
