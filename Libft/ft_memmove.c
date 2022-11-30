/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:38:24 by bvarlamo          #+#    #+#             */
/*   Updated: 2021/07/12 12:42:06 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *to, const void *from, size_t len)
{
	size_t	i;

	i = 0;
	if (!to && !from)
		return (NULL);
	if (to - from > 0)
	{
		while (len > 0)
		{
			len--;
			((char *) to)[len] = ((char *) from)[len];
		}
		return (to);
	}
	while (i < len)
	{
		((char *) to)[i] = ((char *) from)[i];
		i++;
	}
	return (to);
}
