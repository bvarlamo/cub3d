/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:30:40 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/28 09:10:41 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	init_value(char *line, t_values *vars)
{
	char	**tmp;
	bool	ret;

	tmp = ft_split(line, ' ');
	if (!ft_strcmp(tmp[0], "NO"))
		ret = save_tex(tmp, vars, NORTH);
	else if (!ft_strcmp(tmp[0], "SO"))
		ret = save_tex(tmp, vars, SOUTH);
	else if (!ft_strcmp(tmp[0], "WE"))
		ret = save_tex(tmp, vars, WEST);
	else if (!ft_strcmp(tmp[0], "EA"))
		ret = save_tex(tmp, vars, EAST);
	else if (!ft_strcmp(tmp[0], "F"))
		ret = get_color(line, tmp, vars, FLOOR);
	else if (!ft_strcmp(tmp[0], "C"))
		ret = get_color(line, tmp, vars, CEILING);
	else
		return (invalid_data(tmp));
	ft_double_free(tmp);
	return (ret);
}

void	write_nswefc(t_values *vars, char *line)
{
	char	c;

	c = first_char(line);
	if (c == 'N')
		vars->nswefc[0]++;
	else if (c == 'S')
		vars->nswefc[1]++;
	else if (c == 'W')
		vars->nswefc[2]++;
	else if (c == 'E')
		vars->nswefc[3]++;
	else if (c == 'F')
		vars->nswefc[4]++;
	else if (c == 'C')
		vars->nswefc[5]++;
	else if (c == '\0' || c == '\n')
		return ;
	else
		vars->nswefc[6]++;
}

char	first_char(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return ('\0');
	while (line[i] != '\0')
	{
		if (!ft_isspace(line[i]))
			return (line[i]);
		i++;
	}
	return ('\0');
}

void	replace_newline(char *line)
{
	char	*p;

	if (!line)
		return ;
	p = ft_strrchr(line, '\n');
	if (p)
		*p = '\0';
}
