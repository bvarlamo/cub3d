/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:33:17 by bvarlamo          #+#    #+#             */
/*   Updated: 2021/07/14 12:29:37 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, const void *from, size_t size)
{
	char	*cto;
	char	*cfrom;

	cto = (char *)to;
	cfrom = (char *)from;
	if (!to && !from)
		return (NULL);
	while (size > 0)
	{
		*cto = *cfrom;
		cto++;
		cfrom++;
		size--;
	}
	return (to);
}
