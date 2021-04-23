/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 07:46:41 by rvalton           #+#    #+#             */
/*   Updated: 2021/04/06 08:42:09 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init_before_parse(t_all *vars)
{
	vars->rsl.w = 0;
	vars->rsl.h = 0;
	vars->cam.pos.x = 0;
	vars->cam.pos.y = 0;
	vars->cam.dir = '\0';
	if (!(vars->mlx = mlx_init()))
		return (0);
	if (!(vars->map.box = malloc(sizeof(char*))))
		return (0);
	vars->map.box[0] = NULL;
	if (!(vars->spr.path = malloc(sizeof(char*) * 6)))
		return (0);
	vars->spr.path[5] = NULL;
	if (!(vars->spr.data = malloc(sizeof(t_data) * 5)))
		return (0);
	vars->spr.nbspr = 5;
	return (1);
}

int	ft_init_after_parse(t_all *vars)
{
	if (!(vars->wallface = malloc(sizeof(int) * vars->rsl.w)))
		return (0);
	if (!(vars->ray.xtex = malloc(sizeof(int) * vars->rsl.w)))
		return (0);
	return (1);
}
