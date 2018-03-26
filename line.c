/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 19:25:34 by vordynsk          #+#    #+#             */
/*   Updated: 2018/02/23 19:25:37 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line	*ft_coef(t_line *line, t_img *img, t_color color)
{
	line->dx = line->ex - line->bx;
	line->dy = line->ey - line->by;
	if (line->dx = 0)
	{
		vertline(line, img, color);
		return (0);
	}
	line->k = line->dy / line->dx;
	line->b = line->by - line->k * line->bx;
	return (line);
}

void	vertline(t_line *line, t_img *img, t_color color)
{
	if ((line->ey - line->by) > 0)
		while (line->by < line->ey)
		{
			put_pixel(img, line->bx, line->by, color);
			line->by++;
		}
	if ((line->ey - line->by) < 0)
		while (line->by < line->ey)
		{
			put_pixel(img, line->bx, line->by, color);
			line->by--;
		}
}

int		defhline(t_line *line, t_map *map, int i)
{
	line->bx = map->points[i].x;
	line->by = map->points[i].y;
	if (i % map->len == 0)
		return (0);
	line->ex = map->points[i + 1].x;
	line->ey = map->points[i + 1].y;
	return (1);
}

int		defvline(t_line *line, t_map *map, int i)
{
	line->bx = map->points[i].x;
	line->by = map->points[i].y;
	if (i + map->len >= map->len * map->rows)
		return (0);
	line->ex = map->points[i + map->len].x;
	line->ey = map->points[i + map->len].y;
	return (1);
}
