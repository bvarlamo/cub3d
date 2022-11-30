/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:07:13 by bvarlamo          #+#    #+#             */
/*   Updated: 2021/07/15 13:00:25 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		i;

	i = ft_strlen(s);
	copy = (char *)malloc(sizeof(char) * (i + 1));
	if (!(copy))
		return (0);
	while (i >= 0)
	{
		copy[i] = s[i];
		i--;
	}
	return (copy);
}
