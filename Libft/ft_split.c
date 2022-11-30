/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:43:27 by bvarlamo          #+#    #+#             */
/*   Updated: 2021/07/16 20:18:51 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wcount(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
				i++;
			count++;
		}
	}
	return (count);
}

static int	wordlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	**to_free(char **ps)
{
	int	i;

	i = 0;
	while (ps[i])
	{
		free(ps[i]);
		i++;
	}
	free(ps);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		t;
	char	**ps;

	if (!s)
		return (0);
	ps = (char **)malloc(sizeof(char *) * (wcount(s, c) + 1));
	if (!ps)
		return (0);
	i = 0;
	t = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			ps[t] = (char *)ft_substr(s, i, wordlen(&s[i], c));
			if (!(ps[t]))
				return (to_free(ps));
			i = i + ft_strlen(ps[t]) - 1;
			t++;
		}
		i++;
	}
	ps[t] = 0;
	return (ps);
}
