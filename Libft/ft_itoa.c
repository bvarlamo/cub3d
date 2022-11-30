/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:21:38 by bvarlamo          #+#    #+#             */
/*   Updated: 2021/07/12 12:30:55 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*str;
	long int	cn;

	cn = n;
	len = length(cn);
	str = (char *)malloc(len + 1);
	if (str == 0)
		return (0);
	if (n < 0)
	{
		cn = -cn;
		str[0] = '-';
	}
	str[len] = '\0';
	if (cn == 0)
		str[0] = '0';
	while (cn)
	{
		str[len - 1] = cn % 10 + '0';
		cn /= 10;
		len--;
	}
	return (str);
}
