/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:12:12 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/09/29 12:10:21 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	drawwalls(int x, t_values *vars)
{
	int		d;
	char	*pix;

	d = vars->drawstart;
	while (d < vars->drawend)
	{
		vars->tex.y = (int)vars->texpos & (vars->height[vars->texnum] - 1);
		vars->texpos += vars->t_step;
		pix = vars->img + ((int)d * vars->line) + ((int)x * (vars->bits / 8));
		*(unsigned int *) pix = *(unsigned int *)(vars->itex[vars->texnum]
				+ ((int)vars->tex.y * vars->tline[vars->texnum])
				+ ((int)vars->tex.x * (vars->tbits[vars->texnum] / 8)));
		d++;
	}
}

void	draw_mini(t_values *vars, int x, int y, unsigned int color)
{
	char	*pix;
	int		x1;
	int		y1;

	x1 = x * 5;
	while (x1 < ((x * 5) + 5))
	{
		y1 = y * 5;
		while (y1 < ((y * 5) + 5))
		{
			pix = vars->img + (int)x1 * vars->line + (int)y1 * (vars->bits / 8);
			*(unsigned int *)pix = color;
			y1++;
		}
		x1++;
	}
}

void	draw_player(t_values *vars)
{
	double		x1;
	double		y1;
	double		scale;
	char		*pix;

	x1 = vars->pos.x * 5;
	y1 = vars->pos.y * 5;
	scale = 3;
	while (x1 < (vars->pos.x * 5) + 5)
	{
		y1 = (vars->pos.y * 5) + 5 - scale;
		while (y1 < (vars->pos.y * 5) + scale)
		{
			pix = vars->img + (int)x1 * vars->line + (int)y1 * (vars->bits / 8);
			*(unsigned int *)pix = 0xff0000;
			y1++;
		}
		if (x1 >= ((vars->pos.x * 5) + 2))
			scale = scale - 2;
		scale++;
		x1++;
	}
}

void	mini_map(t_values *vars)
{
	int		x;
	int		y;

	x = 0;
	while (vars->map[x])
	{
		y = 0;
		while (vars->map[x][y])
		{
			if (vars->map[x][y] == '1')
				draw_mini(vars, x, y, 0xffffff);
			else if (vars->map[x][y] == '0')
				draw_mini(vars, x, y, 0x000000);
			y++;
		}
		x++;
	}
	draw_player(vars);
}

int	test(t_values *vars)
{
	void	*old_img;

	old_img = vars->img_ptr;
	vars->img_ptr = mlx_new_image(vars->mlx_ptr, SCREENWIDTH, SCREENHEIGHT);
	vars->img = mlx_get_data_addr(vars->img_ptr, &vars->bits, &vars->line,
			&vars->end);
	stepforward(vars);
	stepbackward(vars);
	turnleft(vars);
	turnright(vars);
	stepright(vars);
	stepleft(vars);
	draw_fc(vars);
	raycasting(vars);
	mini_map(vars);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr, 0, 0);
	mlx_destroy_image(vars->mlx_ptr, old_img);
	return (0);
}
