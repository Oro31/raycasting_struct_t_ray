/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 07:52:23 by rvalton           #+#    #+#             */
/*   Updated: 2021/04/08 10:46:44 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isdir(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

char	ft_define_cam(t_all *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map.box[i])
	{
		j = 0;
		while (vars->map.box[i][j])
		{
			if (ft_isdir(vars->map.box[i][j]))
			{
				vars->cam.pos.x = j;
				vars->cam.pos.y = i;
				printf("dir : %c \n", vars->map.box[i][j]);
				return (vars->map.box[i][j]);
			}
			j++;
		}
		i++;
	}
	return ('\0');
}

float	ft_dir_to_fov(char dir)
{
	float	tmp;

	tmp = 0;
	if (dir == 'N')
		tmp = M_PI / 2;
	else if (dir == 'E')
		tmp = 0;
	else if (dir == 'S')
		tmp = 3 * M_PI / 2;
	else if (dir == 'W')
		tmp = M_PI;
	return (tmp);
}
