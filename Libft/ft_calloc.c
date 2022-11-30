/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:04:27 by bvarlamo          #+#    #+#             */
/*   Updated: 2021/07/12 12:24:35 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t eltsize)
{
	size_t	size;
	void	*value;

	size = count * eltsize;
	value = malloc(size);
	if (value != 0)
		ft_bzero(value, size);
	return (value);
}
