/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:40:29 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/28 08:39:36 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	left_border(int i, int j, t_values *vars)
{
	while (j > 0)
	{
		j--;
		if (vars->map[i][j] == '1')
			return (0);
		if (vars->map[i][j] == '0')
		{
			ft_putstr_fd("Error!\nThe map is scrambled.\n", 2);
			return (1);
		}
	}
	return (0);
}

bool	right_border(int i, int j, t_values *vars)
{
	while (vars->map[i][j] && j < vars->nr_columns)
	{
		j++;
		if (vars->map[i][j] == '1')
			return (0);
		if (vars->map[i][j] == '0')
		{
			ft_putstr_fd("Error!\nThe map is scrambled.\n", 2);
			return (1);
		}
	}
	return (0);
}

bool	top_border(int i, int j, t_values *vars)
{
	while (i > 0)
	{
		i--;
		if (vars->map[i][j] == '1')
			return (0);
		if (vars->map[i][j] == '0')
		{
			ft_putstr_fd("Error!\nThe map is scrambled.\n", 2);
			return (1);
		}
	}
	return (0);
}

bool	bottom_border(int i, int j, t_values *vars)
{
	while (i < vars->nr_rows - 1)
	{
		i++;
		if (vars->map[i][j] == '1')
			return (0);
		if (vars->map[i][j] == '0')
		{
			ft_putstr_fd("Error!\nThe map is scrambled.\n", 2);
			return (1);
		}
	}
	return (0);
}
