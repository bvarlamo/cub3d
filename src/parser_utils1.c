/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:31:53 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/30 15:17:37 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	sort_data(t_values *vars, char *line, int *count, bool *ret)
{
	int	j;

	if (*count < 6 && !is_only_whitespaces(line))
	{
		(*count)++;
		if (init_value(line, vars))
			*ret = 1;
	}
	else if ((*count == 6 && !is_only_whitespaces(line)) || *count > 6)
	{
		j = (*count) - 6;
		(*count)++;
		if (j == vars->nr_rows)
			return ;
		ft_strlcpy(vars->map[j++], line, ft_strlen(line) + 1);
	}
}

bool	check_character(char c, t_values *vars, int i, int j)
{
	if (c == '1' || c == '0' || ft_isspace(c) || c == '\0')
		return (0);
	else if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		vars->nr_start_pos++;
		init_pos_and_dir(c, vars, i, j);
		vars->map[i][j] = '0';
		return (0);
	}
	ft_putstr_fd("Error!\nFalse characater on the map.\n", 2);
	return (1);
}

static bool	check_map_more(int i, int j, t_values *vars)
{
	if (check_character(vars->map[i][j], vars, i, j))
		return (1);
	if (vars->map[i][j] == '0')
	{
		if (left_wall(i, j, vars) || right_wall(i, j, vars) \
		|| top_wall(i, j, vars) || bottom_wall(i, j, vars))
			return (1);
	}
	if (ft_isspace(vars->map[i][j]))
	{
		if (top_border(i, j, vars) || bottom_border(i, j, vars) \
		|| left_border(i, j, vars) || right_border(i, j, vars))
			return (1);
	}
	return (0);
}

bool	empty_lines(t_values *vars)
{
	int	i;

	i = 0;
	while (i + 1 < vars->nr_rows)
	{
		if (is_only_whitespaces(vars->map[i]) \
		&& !is_only_whitespaces(vars->map[i + 1]))
		{
			ft_putstr_fd("Error!\nEmpty line(s) on the map.\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

bool	check_map(t_values *vars)
{
	int	i;
	int	j;

	if (empty_lines(vars))
		return (1);
	vars->nr_start_pos = 0;
	i = 0;
	while (i < vars->nr_rows)
	{
		j = 0;
		while (j < vars->nr_columns)
		{
			if (check_map_more(i, j, vars))
				return (1);
			j++;
		}
		i++;
	}
	if (vars->nr_start_pos != 1)
	{
		ft_putstr_fd("Error!\nWrong number of starting positions.\n", 2);
		return (1);
	}
	return (0);
}
