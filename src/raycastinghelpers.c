/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastinghelpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:52:09 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/09/23 14:15:53 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	raycast1(t_values *vars)
{
	vars->ray.x = vars->dir.x + vars->plane.x * vars->camerax;
	vars->ray.y = vars->dir.y + vars->plane.y * vars->camerax;
	vars->move.x = (int)vars->pos.x;
	vars->move.y = (int)vars->pos.y;
	if (vars->ray.x == 0)
		vars->delta.x = 1e30;
	else
		vars->delta.x = fabs(1 / vars->ray.x);
	if (vars->ray.y == 0)
		vars->delta.y = 1e30;
	else
		vars->delta.y = fabs(1 / vars->ray.y);
	if (vars->ray.x < 0)
	{
		vars->step.x = -1;
		vars->side.x = (vars->pos.x - vars->move.x) * vars->delta.x;
	}
	else
	{
		vars->step.x = 1;
		vars->side.x = (vars->move.x + 1.0 - vars->pos.x) * vars->delta.x;
	}
}

void	raycast2(t_values *vars)
{
	if (vars->ray.y < 0)
	{
		vars->step.y = -1;
		vars->side.y = (vars->pos.y - vars->move.y) * vars->delta.y;
	}
	else
	{
		vars->step.y = 1;
		vars->side.y = (vars->move.y + 1.0 - vars->pos.y) * vars->delta.y;
	}
}

void	raycast3(t_values *vars)
{
	vars->hit = 0;
	while (vars->hit == 0)
	{
		if (vars->side.x < vars->side.y)
		{
			vars->side.x += vars->delta.x;
			vars->move.x += vars->step.x;
			vars->p_side = 0;
		}
		else
		{
			vars->side.y += vars->delta.y;
			vars->move.y += vars->step.y;
			vars->p_side = 1;
		}
		if (vars->map[vars->move.x][vars->move.y] == '1')
			vars->hit = 1;
	}
}

void	raycast4(t_values *vars)
{
	if (vars->p_side == 0)
		vars->perpwalldist = (vars->side.x - vars->delta.x);
	else
		vars->perpwalldist = (vars->side.y - vars->delta.y);
	vars->h = SCREENHEIGHT;
	vars->lineheight = (int)(vars->h / vars->perpwalldist);
	vars->drawstart = -vars->lineheight / 2 + vars->h / 2;
	if (vars->drawstart < 0)
		vars->drawstart = 0;
	vars->drawend = vars->lineheight / 2 + vars->h / 2;
	if (vars->drawend >= vars->h)
		vars->drawend = vars->h - 1;
	if (vars->p_side == 1 && vars->move.y > (vars->move.y - vars->step.y))
		vars->texnum = 0;
	else if (vars->p_side == 1 && vars->move.y < (vars->move.y - vars->step.y))
		vars->texnum = 1;
	else if (vars->p_side == 0 && vars->move.x < (vars->move.x - vars->step.x))
		vars->texnum = 2;
	else if (vars->p_side == 0 && vars->move.x > (vars->move.x - vars->step.x))
		vars->texnum = 3;
	if (vars->p_side == 0)
		vars->wallx = vars->pos.y + vars->perpwalldist * vars->ray.y;
	else
		vars->wallx = vars->pos.x + vars->perpwalldist * vars->ray.x;
	vars->wallx -= floor((vars->wallx));
}

void	raycast5(t_values *vars)
{
	vars->tex.x = (int)(vars->wallx * (double)vars->height[vars->texnum]);
	if (vars->p_side == 0 && vars->ray.x > 0)
		vars->tex.x = vars->width[vars->texnum] - vars->tex.x - 1;
	if (vars->p_side == 1 && vars->ray.y < 0)
		vars->tex.x = vars->width[vars->texnum] - vars->tex.x - 1;
	vars->t_step = 1.0 * vars->height[vars->texnum] / vars->lineheight;
	vars->texpos = (vars->drawstart - vars->h / 2 + vars->lineheight / 2)
		* vars->t_step;
}
