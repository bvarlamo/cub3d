/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:48:43 by bvarlamo          #+#    #+#             */
/*   Updated: 2021/07/12 12:43:45 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
		{
			return ((char *)str + i);
		}
		i++;
	}
	if (str[i] == (unsigned char)c)
		return ((char *)str + i);
	return (0);
}
