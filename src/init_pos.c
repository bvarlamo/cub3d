/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:42:24 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/28 16:31:41 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_e(t_values *vars)
{
	vars->dir.x = 0;
	vars->dir.y = 1;
	vars->plane.x = 0.66;
	vars->plane.y = 0;
}

void	init_w(t_values *vars)
{
	vars->dir.x = 0;
	vars->dir.y = -1;
	vars->plane.x = -0.66;
	vars->plane.y = 0;
}

void	init_s(t_values *vars)
{
	vars->dir.x = 1;
	vars->dir.y = 0;
	vars->plane.x = 0;
	vars->plane.y = -0.66;
}

void	init_n(t_values *vars)
{
	vars->dir.x = -1;
	vars->dir.y = 0;
	vars->plane.x = 0;
	vars->plane.y = 0.66;
}

void	init_pos_and_dir(char c, t_values *vars, int i, int j)
{
	vars->pos.x = i + 0.5;
	vars->pos.y = j + 0.5;
	if (c == 'N')
		init_n(vars);
	else if (c == 'S')
		init_s(vars);
	else if (c == 'W')
		init_w(vars);
	else if (c == 'E')
		init_e(vars);
	vars->w = 0;
	vars->s = 0;
	vars->a = 0;
	vars->d = 0;
	vars->left = 0;
	vars->right = 0;
	vars->old_x = 0;
}
