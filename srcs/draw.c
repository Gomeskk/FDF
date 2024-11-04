/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:20:31 by joafaust          #+#    #+#             */
/*   Updated: 2024/11/04 15:52:07 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/colors.h"
#include "../incl/fdf.h"
#include "../LIBFT/libft.h"
#include "../minilibx-linux/mlx.h"

/*
** Put pixel into map image
*/

static void	put_pix(t_fdf *fdf, int x, int y, int color)
{
	int	i;

	if (x >= MENU_WIDTH && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * fdf->bits_p_pix / 8) + (y * fdf->size_line);
		fdf->data_addr[i] = color;
		fdf->data_addr[++i] = color >> 8;
		fdf->data_addr[++i] = color >> 16;
	}
}

/*
** Draw line
*/
void	set_sign(t_point *sign, t_point f, t_point s)
{
	if (f.x < s.x)
		sign->x = 1;
	else
		sign->x = -1;
	if (f.y < s.y)
		sign->y = 1;
	else
		sign->y = -1;
}

static void	draw_l(t_point f, t_point s, t_fdf *fdf)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error[2];

	delta.x = FT_ABS(s.x - f.x);
	delta.y = FT_ABS(s.y - f.y);
	set_sign(&sign, f, s);
	error[0] = delta.x - delta.y;
	cur = f;
	while (cur.x != s.x || cur.y != s.y)
	{
		put_pix(fdf, cur.x, cur.y, get_color(cur, f, s, delta));
		error[1] = error[0] * 2;
		if ((error[1]) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

/*
** Draw background colors (Menu background + main background)
*/

static void	draw_backg(t_fdf *fdf)
{
	int	*image;
	int	i;

	ft_bzero(fdf->data_addr, WIDTH * HEIGHT * (fdf->bits_p_pix / 8));
	image = (int *)(fdf->data_addr);
	i = 0;
	while (i < HEIGHT * WIDTH)
	{
		if (i % WIDTH < MENU_WIDTH)
			image[i] = MENU_BACKGROUND;
		else
			image[i] = BACKGROUND;
		i++;
	}
}

/*
** Draw image
*/

void	draw(t_map *map, t_fdf *fdf)
{
	int	x;
	int	y;

	draw_backg(fdf);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x != fdf->map->width - 1)
				draw_l(project(n_point(x, y, map), fdf), project(n_point(x + 1,
							y, map), fdf), fdf);
			if (y != fdf->map->height - 1)
				draw_l(project(n_point(x, y, map), fdf), project(n_point(x, y
							+ 1, map), fdf), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	print_menu(fdf);
}
