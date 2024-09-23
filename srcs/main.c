/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:30:38 by joafaust          #+#    #+#             */
/*   Updated: 2024/09/23 13:31:30 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
void	draw_square(t_data *img, int x, int y, int side, int color)
{
	for (int i = 0; i < side; i++)
	{
		for (int j = 0; j < side; j++)
		{
			my_mlx_pixel_put(img, x + i, y + j, color);
		}
	}
}
void	draw_circle(t_data *img, int x0, int y0, int radius, int color)
{
	for (int x = -radius; x <= radius; x++)
	{
		for (int y = -radius; y <= radius; y++)
		{
			if (x * x + y * y <= radius * radius)
				my_mlx_pixel_put(img, x0 + x, y0 + y, color);
		}
	}
}
void	draw_triangle(t_data *img, int x, int y, int size, int color)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			my_mlx_pixel_put(img, x + j, y + i, color);
			my_mlx_pixel_put(img, x - j, y + i, color);
		}
	}
}
void	draw_hexagon(t_data *img, int x0, int y0, int size, int color)
{
	for (int y = -size; y <= size; y++)
	{
		for (int x = -size; x <= size; x++)
		{
			if ((abs(x) + abs(y)) <= size)  // hexagon logic
				my_mlx_pixel_put(img, x0 + x, y0 + y, color);
		}
	}
}


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1320, 600, "Hello world!");
	img.img = mlx_new_image(mlx, 1320, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	// Drawing shapes
	draw_square(&img, 50, 50, 100, 0x00FF0000);      // Red square
	draw_circle(&img, 300, 150, 50, 0x0000FF00);     // Green circle
	draw_triangle(&img, 500, 100, 50, 0x000000FF);   // Blue triangle
	draw_hexagon(&img, 700, 150, 50, 0x00FFFF00);    // Yellow hexagon
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
/* int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	if (!mlx)
	{
		printf("Failed to initialize MLX.\n");
		return (1);
	}

	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 100, 100);
	if (!img.img)
	{
		printf("Failed to create image.\n");
		return (1);
	}

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	if (!img.addr)
	{
		printf("Failed to get image address.\n");
		return (1);
	}

	// Print debug info
	printf("Bits per pixel: %d, Line length: %d, Endian: %d\n", img.bits_per_pixel, img.line_length, img.endian);

	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
} */

