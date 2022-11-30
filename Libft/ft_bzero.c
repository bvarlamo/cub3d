/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:31:47 by bvarlamo          #+#    #+#             */
/*   Updated: 2021/07/12 12:21:45 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *block, size_t size)
{
	unsigned char	*block_copy;

	block_copy = block;
	while (size > 0)
	{
		*block_copy = '\0';
		block_copy++;
		size--;
	}
}
