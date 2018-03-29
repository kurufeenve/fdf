/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 14:24:58 by vordynsk          #+#    #+#             */
/*   Updated: 2018/03/29 14:25:00 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	turn_x(t_map *map, double alpha)
{
	double	cosa;
	double	sina;
	int		i;

	i = 0;
	cosa = cos(alpha);
	sina = sin(alpha);
	while (i < map->rows * map->len)
	{
		map->points[i].y = map->points[i].y * cosa + map->points[i].z * sina;
		map->points[i].z = map->points[i].z * cosa - map->points[i].y * sina;
		i++;
	}
}

void	turn_y(t_map *map, double alpha)
{
	double	cosa;
	double	sina;
	int		i;

	i = 0;
	cosa = cos(alpha);
	sina = sin(alpha);
	while (i < map->rows * map->len)
	{
		map->points[i].x = map->points[i].x * cosa + map->points[i].z * sina;
		map->points[i].z = map->points[i].z * cosa - map->points[i].x * sina;
		i++;
	}
}

void	turn_z(t_map *map, double alpha)
{
	double	cosa;
	double	sina;
	int		i;

	i = 0;
	cosa = cos(alpha);
	sina = sin(alpha);
	while (i < map->rows * map->len)
	{
		map->points[i].x = map->points[i].x * cosa - map->points[i].y * sina;
		map->points[i].y = map->points[i].y * cosa + map->points[i].x * sina;
		i++;
	}
}
