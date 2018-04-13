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
#include <stdio.h>
#include "fdf.h"

void	turn(t_general *gen, double a, double b, double g)
{
	int		i;
	double	tmpx;
	double	tmpy;
	double	tmpz;

	i = 0;
	ft_clearscr(&gen->img, &gen->mlx);
	//printf("1. x = %f, y = %f, z = %f\n", gen->map.points[0].x, gen->map.points[0].y, gen->map.points[0].z);
	while (i < gen->map.len * gen->map.rows)
	{
		tmpx = gen->map.points[i].x;
		tmpy = gen->map.points[i].y;
		tmpz = gen->map.points[i].z;
		gen->map.points[i].x = tmpx * cos(b) * cos(g) + tmpz * sin(b) -
		tmpy * cos(b) * sin(g);
		gen->map.points[i].y = -tmpz * cos(b) * sin(a) + tmpx * (cos(g) *
		sin (a) * sin(b) + cos(a) * sin(g)) + tmpy * (cos(a) * cos(g) -
		sin(a) * sin(b) * sin(g));
		gen->map.points[i].z = tmpz * cos(a) * cos(b) + tmpx * (sin(a) *
		sin(g) - cos(a) * cos(g) * sin(b)) + tmpy * (cos(g) * sin(a) +
		cos(a) * sin(b) * sin(g));
		i++;
	}
	//printf("2. x = %f, y = %f, z = %f\n", gen->map.points[0].x, gen->map.points[0].y, gen->map.points[0].z);
	ft_line(gen);
	mlx_put_image_to_window(gen->mlx.init, gen->mlx.win, gen->img.img, gen->mlx.size_x / 2, gen->mlx.size_y / 2);
}

void	ft_line(t_general *gen)
{
	int		i;

	i = 0;
	while (i < gen->map.len * gen->map.rows)
	{
		defline(&gen->line, &gen->map, i, 0);
		if (coefline(gen) == 1)
			plotline(gen);
		defline(&gen->line, &gen->map, i, 1);
		if (coefline(gen) == 1)
			plotline(gen);
		i++;
	}
	printf("\n========\n\n");
}
