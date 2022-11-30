/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:38:18 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/30 15:00:39 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	xclose(t_values *vars)
{
	free_everything(vars);
	return (0);
}

void	raycasting(t_values *vars)
{
	double	w;
	int		x;

	w = SCREENWIDTH;
	x = 0;
	while (x < w)
	{
		vars->camerax = 2 * x / w - 1;
		raycast1(vars);
		raycast2(vars);
		raycast3(vars);
		raycast4(vars);
		raycast5(vars);
		drawwalls(x, vars);
		x++;
	}
}

int	init_mlx(t_values *vars)
{
	vars->mlx_ptr = mlx_init();
	if (vars->mlx_ptr == NULL)
		return (1);
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, SCREENWIDTH,
			SCREENHEIGHT, "Cub3D");
	if (vars->win_ptr == NULL)
		return (1);
	vars->img_ptr = mlx_new_image(vars->mlx_ptr, SCREENWIDTH, SCREENHEIGHT);
	if (vars->img_ptr == NULL)
		return (1);
	vars->img = mlx_get_data_addr(vars->img_ptr, &vars->bits,
			&vars->line, &vars->end);
	if (vars->img == NULL)
		return (1);
	return (0);
}

bool	check_file(int argc, char *argv)
{
	int	i;

	if (argc != 2)
	{
		ft_putstr_fd("Error!\nWrong number of arguments!  Use a cub file.\n", 2);
		return (1);
	}
	i = ft_strlen(argv) - 1;
	if (i < 4 || argv[i] != 'b' || argv[i - 1] != 'u' || argv[i - 2] != 'c'\
	|| argv[i - 3] != '.')
	{
		ft_putstr_fd("Error!\nUse a .cub file.\n", 2);
		return (1);
	}
	return (0);
}

bool	init_to_null(t_values *vars)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		vars->pattern[i] = NULL;
		vars->t_tex[i] = NULL;
		vars->itex[i] = NULL;
		i++;
	}
	vars->map = NULL;
	vars->img_ptr = NULL;
	vars->win_ptr = NULL;
	vars->mlx_ptr = NULL;
	return (0);
}
