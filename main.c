/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:00:03 by vordynsk          #+#    #+#             */
/*   Updated: 2018/02/12 14:00:05 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "fdf.h"

int		key_hook(int key, void *ptr)
{
	if (ptr == NULL)
		printf("key pressed = %d\n", key);
	if (key == 53)
	{
		printf("\033[0;31mEXIT\033[0m\n");
		exit (0);
	}
	return (0);
}

void	put_pixel(t_img *img, int x, int y, t_color color)
{
	img->image[y * img->val + 4 * x] = color.channel[0];
	img->image[y * img->val + 4 * x + 1] = color.channel[1];
	img->image[y * img->val + 4 * x + 2] = color.channel[2];
}

int exit_x(void)
{
	exit(1);
}

int		main(int argc, char **argv)
{
	t_mlx	*ent;
	t_line	*line1;
	t_line	*line2;
	t_img	*img;
	t_color	color;
	t_map	*map;

	if (argc > 2)
		return (0);
	init_map(&map);
	ft_map(argv[1], map);
	mlx_struct_null(&ent);
	init_line(&line1);
	init_line(&line2);
	init_img(&img);
	system("leaks fdf");
	ent->init = mlx_init();
	ent->size_x = 1000;
	ent->size_y = 1000;
	if (ent->init == NULL)
		return (0);
	ent->win = mlx_new_window(ent->init, ent->size_x, ent->size_y, "test");
	if (ent->win == NULL)
		return (0);
	ft_recalc(map, ent);
	line1->bx = 1;
	line1->by = 1;
	line1->ex = 2;
	line1->ey = 4;
	//printf("line1->k = %f\nline1->b = %f\n", line1->k, line1->b);
	img->img = mlx_new_image(ent->init, ent->size_x, ent->size_y);
	if (img->img == NULL)
		return (0);
	img->image = mlx_get_data_addr(img->img, &img->bpp, &img->val, &img->ed);
	color.color = 0xFFFFFF;
	ft_coef(line1, img, color);
	ft_drawpoints(map, img, color, line2);
	ft_line(line2, map, color, img);
	mlx_put_image_to_window(ent->init, ent->win, img->img, 0, 0);
	mlx_hook(ent->win, 2, 5, key_hook, NULL);
	mlx_hook(ent->win, 17, 1L << 17, exit_x, NULL);
	mlx_loop(ent->init);
	return (0);
}
