/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:17:07 by bvarlamo          #+#    #+#             */
/*   Updated: 2021/07/16 19:51:04 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	beginning;
	size_t	end;
	char	*trim;

	if (!s1)
		return (0);
	if (s1[0] == '\0')
		return (ft_strdup("\0"));
	beginning = 0;
	while (s1[beginning] && ft_strchr(set, s1[beginning]))
		beginning++;
	end = (ft_strlen(s1) - 1);
	while (ft_strchr(set, s1[end]) && end > beginning)
		end--;
	trim = ft_substr(s1, beginning, (end - beginning + 1));
	if (!(trim))
		return (0);
	return (trim);
}
