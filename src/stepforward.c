/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stepforward.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 12:23:25 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/28 15:08:33 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	stepforward(t_values *vars)
{
	if (vars->w == 1)
	{
		if (vars->map[(int)(vars->pos.x + vars->dir.x
				* (STEP_INTERVAL * 2))][(int)(vars->pos.y)] == '0')
			vars->pos.x += vars->dir.x * STEP_INTERVAL;
		if (vars->map[(int)(vars->pos.x)][(int)(vars->pos.y
				+ vars->dir.y * (STEP_INTERVAL * 2))] == '0')
			vars->pos.y += vars->dir.y * STEP_INTERVAL;
	}
}

void	stepbackward(t_values *vars)
{
	if (vars->s == 1)
	{
		if (vars->map[(int)(vars->pos.x - vars->dir.x
				* (STEP_INTERVAL * 2))][(int)(vars->pos.y)] == '0')
				vars->pos.x -= vars->dir.x * STEP_INTERVAL;
		if (vars->map[(int)(vars->pos.x)][(int)(vars->pos.y
				- vars->dir.y * (STEP_INTERVAL * 2))] == '0')
			vars->pos.y -= vars->dir.y * STEP_INTERVAL;
	}
}
