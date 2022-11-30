/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:39:44 by bvarlamo          #+#    #+#             */
/*   Updated: 2021/07/12 12:45:21 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_s;
	unsigned int	i;

	if (!s || !f)
		return (0);
	new_s = ft_strdup((const char *)s);
	if (!(new_s))
		return (0);
	i = 0;
	while (new_s[i] != 0)
	{
		new_s[i] = f(i, new_s[i]);
		i++;
	}
	return (new_s);
}
