/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 13:55:13 by bvarlamo          #+#    #+#             */
/*   Updated: 2021/07/20 12:08:21 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*t;
	t_list	*i;

	t = *lst;
	while (t)
	{
		i = t->next;
		del(t->content);
		free(t);
		t = i;
	}
	*lst = NULL;
}
