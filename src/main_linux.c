/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_linux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 08:32:53 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/30 15:05:44 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_fc(t_values *vars)
{
	int		x;
	int		y;
	char	*pix;

	x = 0;
	vars->color = vars->ceiling;
	while (x < SCREENHEIGHT)
	{
		if (x == SCREENHEIGHT / 2)
			vars->color = vars->floor;
		y = 0;
		while (y < SCREENWIDTH)
		{
			pix = vars->img + (int)x * vars->line + (int)y * (vars->bits / 8);
			*(unsigned int *)pix = vars->color;
			y++;
		}
		x++;
	}
}

bool	free_everything(t_values *vars)
{
	int	i;

	i = 0;
	ft_double_free(vars->map);
	if (vars->img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->img_ptr);
	i = 0;
	while (i < 4)
	{
		if (vars->pattern[i])
			free(vars->pattern[i]);
		if (vars->t_tex[i])
			mlx_destroy_image(vars->mlx_ptr, vars->t_tex[i]);
		i++;
	}
	if (vars->win_ptr)
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	if (vars->mlx_ptr)
	{
		mlx_destroy_display(vars->mlx_ptr);
		free(vars->mlx_ptr);
	}
	exit(1);
}

int	mouse(int x, int y, t_values *vars)
{
	if (y && x < vars->old_x)
	{
		vars->olddirx = vars->dir.x;
		vars->dir.x = vars->dir.x * cos(TURN) - vars->dir.y * sin(TURN);
		vars->dir.y = vars->olddirx * sin(TURN) + vars->dir.y * cos(TURN);
		vars->oldplanex = vars->plane.x;
		vars->plane.x = vars->plane.x * cos(TURN) - vars->plane.y * sin(TURN);
		vars->plane.y = vars->oldplanex * sin(TURN) + vars->plane.y * cos(TURN);
	}
	else if (y && x > vars->old_x)
	{
		vars->olddirx = vars->dir.x;
		vars->dir.x = vars->dir.x * cos(-1 * TURN)
			- vars->dir.y * sin(-1 * TURN);
		vars->dir.y = vars->olddirx * sin(-1 * TURN)
			+ vars->dir.y * cos(-1 * TURN);
		vars->oldplanex = vars->plane.x;
		vars->plane.x = vars->plane.x * cos(-1 * TURN) - vars->plane.y
			* sin(-1 * TURN);
		vars->plane.y = vars->oldplanex * sin(-1 * TURN) + vars->plane.y
			* cos(-1 * TURN);
	}
	vars->old_x = x;
	return (0);
}

int	keys_release(int key, t_values *vars)
{
	if (key == EXIT_KEY)
		xclose(vars);
	else if (key == W_KEY)
		vars->w = 0;
	else if (key == S_KEY)
		vars->s = 0;
	else if (key == A_KEY)
		vars->a = 0;
	else if (key == D_KEY)
		vars->d = 0;
	else if (key == LEFT_ARROW)
		vars->left = 0;
	else if (key == RIGHT_ARROW)
		vars->right = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_values		vars;

	if (check_file(argc, argv[1]))
		return (1);
	if (init_to_null(&vars) || parse_input(argv[1], &vars))
		return (free_map(&vars));
	if (init_mlx(&vars))
	{
		ft_putstr_fd("Error!\nMLX not running.\n", 2);
		return (free_everything(&vars));
	}
	if (textures(&vars))
		return (free_everything(&vars));
	mlx_hook(vars.win_ptr, 2, 1L << 0, keys, &vars);
	mlx_hook(vars.win_ptr, 3, 1L << 1, keys_release, &vars);
	mlx_hook(vars.win_ptr, 6, 1L << 6, mouse, &vars);
	mlx_hook(vars.win_ptr, 17, 0, xclose, &vars);
	mlx_loop_hook(vars.mlx_ptr, test, &vars);
	mlx_loop(vars.mlx_ptr);
	free_everything(&vars);
	return (0);
}
