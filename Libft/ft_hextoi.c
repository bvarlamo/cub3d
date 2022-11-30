/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:20:44 by bvarlamo          #+#    #+#             */
/*   Updated: 2021/12/13 11:31:48 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_int(char c)
{
	if (ft_isalpha(c))
		return (ft_toupper(c) - 'A' + 10);
	else
		return (c - '0');
}

int	ft_hextoi(char	*hex)
{
	int		len;
	int		power;
	int		dec;
	int		i;

	len = ft_strlen(hex) - 1;
	power = 1;
	dec = 0;
	i = len;
	if (hex[i] == '\n')
		i --;
	while (i >= 0)
	{
		dec += get_int(hex[i]) * power;
		power *= 16;
		i--;
	}
	return (dec);
}
