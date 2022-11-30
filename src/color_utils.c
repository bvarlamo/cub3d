/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:25:14 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/09/28 16:29:22 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	create_trgb(int t, int r, int g, int b)
{
	int	trgb;

	trgb = t << 24 | r << 16 | g << 8 | b;
	return (trgb);
}

void	slide(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		line[i] = line[i + 1];
		i++;
	}
}

char	*slide_line(char *line)
{
	int	i;

	slide(line);
	i = 0;
	while (ft_isspace(line[i]))
		slide(line);
	while (line[i])
	{
		while (line[i + 1] == ',' && ft_isspace(line[i]))
		{
			slide(&line[i]);
			if (i > 0)
				i--;
		}
		while (line[i] == ',' && ft_isspace(line[i + 1]))
			slide(&line[i + 1]);
		i++;
	}
	i--;
	while (ft_isspace(line[i]))
		line[i--] = '\0';
	return (line);
}

int	get_color2(char *color, t_values *vars, int i)
{
	char	**tmp;
	t_color	l;

	tmp = ft_split(color, ',');
	if (!tmp[2] || tmp[3] || count_commas(color) != 2)
		return (color_err(tmp));
	if (!ft_strisdigit(tmp[0]) || !ft_strisdigit(tmp[1])
		|| !ft_strisdigit(tmp[2]))
		return (color_err(tmp));
	l.red = ft_atoi(tmp[0]);
	l.green = ft_atoi(tmp[1]);
	l.blue = ft_atoi(tmp[2]);
	if (l.red < 0 || l.red > 255 || l.green < 0 || l.green > 255 \
	|| l.blue < 0 || l.blue > 255)
		return (color_err(tmp));
	ft_double_free(tmp);
	if (i == FLOOR)
		vars->floor = create_trgb(0, l.red, l.green, l.blue);
	else if (i == CEILING)
		vars->ceiling = create_trgb(0, l.red, l.green, l.blue);
	return (0);
}

int	get_color(char *line, char **tmp, t_values *vars, int i)
{
	char	*color;

	if (!tmp[1])
	{
		ft_putstr_fd("Error!\nInvalid data: color\n", 2);
		return (1);
	}
	if (tmp[2])
		color = slide_line(line);
	else
		color = tmp[1];
	return (get_color2(color, vars, i));
}
