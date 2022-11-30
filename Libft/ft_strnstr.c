/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:51:58 by bvarlamo          #+#    #+#             */
/*   Updated: 2021/07/14 17:58:53 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haysstack, const char *needle, size_t len)
{
	size_t	i;
	char	*g;
	size_t	t;

	i = 0;
	if (!needle[i])
		return ((char *)haysstack);
	while (i < len && haysstack[i])
	{
		if ((len - i) < ft_strlen(needle))
			return (0);
		g = (char *)haysstack + i;
		t = ft_memcmp(&haysstack[i], needle, ft_strlen(needle));
		if (t == 0)
			return (g);
		i++;
	}
	return (0);
}
