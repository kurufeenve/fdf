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
	t_general	*g;
	g = ptr;
	if (ptr == NULL)
		return (0);
	if (key == 126)
		turn(ptr, 0.087266462599716, 0, 0);
	else if (key == 125)
		turn(ptr, -0.087266462599716, 0, 0);
	else if (key == 124)
		turn(ptr, 0, 0.087266462599716, 0);
	else if (key == 123)
		turn(ptr, 0, -0.087266462599716, 0);
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
	printf("\033[0;31mEXIT\033[0m\n");
	exit(1);
}

void	read_image(t_img *img, t_mlx *mlx)
{
	int		i;

	i = 0;
	while (i < mlx->size_x * mlx->size_y * 4)
		printf("%d", (unsigned char)img->image[i++]);
}

int		main(int argc, char **argv)
{
	t_general	gen;

	if (argc > 2)
		return (0);
	init_gen(&gen);
	ft_map(argv[1], &gen.map);
	printf("test1\n");
	gen.mlx.init = mlx_init();
	gen.mlx.size_x = 1000;
	gen.mlx.size_y = 1000;
	if (gen.mlx.init == NULL)
		return (0);
	gen.mlx.win = mlx_new_window(gen.mlx.init, gen.mlx.size_x, gen.mlx.size_y, "test");
	if (gen.mlx.win == NULL)
		return (0);
	ft_recalc(&gen.map, &gen.mlx);
	gen.img.img = mlx_new_image(gen.mlx.init, gen.mlx.size_x, gen.mlx.size_y);
	if (gen.img.img == NULL)
		return (0);
	gen.img.image = mlx_get_data_addr(gen.img.img, &gen.img.bpp, &gen.img.val, &gen.img.ed);
	gen.color.color = 0xFFFFFF;
	ft_line(&gen.line, &gen.map, gen.color, &gen.img);
	mlx_put_image_to_window(gen.mlx.init, gen.mlx.win, gen.img.img, 49, 49);
	mlx_hook(gen.mlx.win, 2, 5, key_hook, &gen);
	mlx_hook(gen.mlx.win, 17, 1L << 17, exit_x, NULL);
	system("leaks fdf");
	mlx_loop(gen.mlx.init);
	return (0);
}
