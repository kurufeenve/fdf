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

void	turn(t_map *map, double a, double b, double g)
{
	int		i;

	i = 0;
	while (i < map->len * map->rows)
	{
		map->points[i].x = map->points[i].x * cos(b) * cos(g) + map->points[i].z * sin(b) - map->points[i].y * cos(b) * sin(g);
		map->points[i].y = -map->points[i].z * cos(b) * sin(a) + map->points[i].x * (cos(g) * sin (a) * sin(b) + cos(a) * sin(g)) + map->points[i].y * (cos(a) * cos(g) - sin(a) * sin(b) * sin(g));
	}
}
