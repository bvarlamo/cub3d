/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:42:24 by bvarlamo          #+#    #+#             */
/*   Updated: 2021/07/12 12:35:12 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *a1, const void *a2, size_t size)
{
	size_t		i;

	i = 0;
	if (!size)
		return (0);
	while (((unsigned char *)a1)[i] == ((unsigned char *)a2)[i])
	{
		if (i == size - 1 || !size)
			return (0);
		i++;
	}
	return (((unsigned char *)a1)[i] - ((unsigned char *)a2)[i]);
}
