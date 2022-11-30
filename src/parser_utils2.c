/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:29:32 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/09/30 15:17:29 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	count_commas(char *s)
{
	int	i;
	int	commas;

	commas = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == ',')
			commas++;
		i++;
	}
	return (commas);
}

bool	save_tex(char **tmp, t_values *vars, int i)
{
	char	*pattern;

	if (!tmp[1] || tmp[2])
	{
		ft_putstr_fd("Error!\nInvalid data: wall texture.\n", 2);
		return (1);
	}
	pattern = tmp[1];
	vars->pattern[i] = malloc(sizeof(char) * (ft_strlen(pattern) + 1));
	if (!vars->pattern[i])
	{
		ft_putstr_fd("Error!\nMemory allocation failed.\n", 2);
		free_everything(vars);
		exit(0);
	}
	ft_strlcpy(vars->pattern[i], pattern, ft_strlen(pattern) + 1);
	return (0);
}

bool	textures(t_values *vars)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		(vars->t_tex[i] = mlx_xpm_file_to_image(vars->mlx_ptr, vars->pattern[i],
					&vars->width[i], &vars->height[i]));
		if (!vars->t_tex[i])
		{
			ft_putstr_fd("Error!\nCheck file path for wall pattern.\n", 2);
			return (1);
		}
		(vars->itex[i] = mlx_get_data_addr(vars->t_tex[i], &vars->tbits[i],
					&vars->tline[i], &vars->tend[i]));
		if (!vars->itex[i++])
		{
			ft_putstr_fd("Error!\nProblem connecting file with minilibx.\n", 2);
			return (1);
		}
	}
	return (0);
}

static char	*copy_with_spaces(char *new, char *line)
{
	int	i;
	int	j;
	int	spaces;

	i = 0;
	j = 0;
	while (line[j])
	{
		if (line[j] == '\t')
		{
			spaces = 0;
			while (spaces < TAB)
			{
				new[i++] = ' ';
				spaces++;
			}
		}
		else
			new[i++] = line[j];
		j++;
	}
	new[i] = '\0';
	return (new);
}

char	*replace_tabs(char *line)
{
	int		i;
	int		count;
	char	*new;

	i = 0;
	count = 0;
	if (!line)
		return (0);
	while (line[i])
		if (line[i++] == '\t')
			count++;
	if (count)
	{
		new = malloc(sizeof(char) * (1 + ft_strlen(line)
					+ (count * (TAB - 1))));
		if (!new)
			return (0);
		new = copy_with_spaces(new, line);
		free(line);
		return (new);
	}
	return (line);
}
