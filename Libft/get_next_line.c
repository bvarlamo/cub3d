/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:22:26 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/23 11:22:56 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_newline(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*increase_buffer(int fd, char *buf)
{
	char	*more_buf;
	int		return_value;

	return_value = 1;
	more_buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!more_buf)
		return (NULL);
	while (!is_newline(buf) && return_value)
	{
		return_value = read(fd, more_buf, BUFFER_SIZE);
		if (return_value < 0)
		{
			free(more_buf);
			return (NULL);
		}
		more_buf[return_value] = '\0';
		buf = ft_strjoin_gnl(buf, more_buf);
	}
	free (more_buf);
	return (buf);
}

static char	*get_line(char *buf)
{
	int		i;
	char	*out_line;

	i = 0;
	if (!buf[i])
		return (0);
	while (buf[i] != '\n' && buf[i])
		i++;
	out_line = malloc(sizeof(char) * (i + 2));
	if (!out_line)
		return (0);
	i = 0;
	while (buf[i] != '\n' && buf[i])
	{
		out_line[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		out_line[i++] = '\n';
	out_line[i] = '\0';
	return (out_line);
}

char	*move_pointer(char *buf)
{
	int		i;
	int		j;
	char	*new_line;
	int		len;

	i = 0;
	j = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	if (!buf[i])
	{
		free (buf);
		return (0);
	}
	len = ft_strlen(buf) - i;
	new_line = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_line)
		return (0);
	i++;
	while (buf[i])
		new_line[j++] = buf[i++];
	new_line[j] = '\0';
	free (buf);
	return (new_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf;

	if (fd < 0)
		return (0);
	if (BUFFER_SIZE <= 0)
		return (0);
	buf = increase_buffer(fd, buf);
	if (!buf)
		return (0);
	line = get_line(buf);
	buf = move_pointer(buf);
	return (line);
}
