/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:15:21 by bvarlamo          #+#    #+#             */
/*   Updated: 2021/07/12 12:42:19 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *block, int c, size_t size)
{
	unsigned char	*block_copy;

	block_copy = block;
	while (size > 0)
	{
		*block_copy = (unsigned char)c;
		block_copy++;
		size--;
	}
	return (block);
}
