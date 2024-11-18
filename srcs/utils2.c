/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:27:22 by joafaust          #+#    #+#             */
/*   Updated: 2024/11/18 16:21:17 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIBFT/libft.h"
#include "../incl/fdf.h"
#include "../minilibx-linux/mlx.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

/*
** Get percent
*/

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return (placement / distance);
}

/*
** Terminate execution and display error message
*/

void	terminate(char *s, t_fdf *fdf)
{
	if (fdf)
		fdf_free(fdf);
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

void	fdf_free(t_fdf *fdf)
{
	if (!fdf)
		return ;
	if (fdf->img)
		mlx_destroy_image(fdf->mlx, fdf->img);
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->mlx)
		mlx_destroy_display(fdf->mlx);
	if (fdf->cam)
		free(fdf->cam);
	if (fdf->mlx)
		free(fdf->mlx);
	if (fdf->map)
	{
		free(fdf->map->order_arr);
		free(fdf->map->colors_arr);
		free(fdf->map);
	}
	if (fdf->mouse)
		free(fdf->mouse);
	free(fdf);
}

/*
** Get index in array by x and y
*/

int	get_index(int x, int y, int width)
{
	return (y * width + x);
}

/*
** Create t_point element (x value + y value + z value + color value)
*/

t_point	n_point(int x, int y, t_map *map)
{
	t_point	point;
	int		index;

	index = get_index(x, y, map->width);
	point.x = x;
	point.y = y;
	point.z = map->order_arr[index];
	if (map->colors_arr[index] == -1)
		point.color = get_def_color(point.z, map);
	else
		point.color = map->colors_arr[index];
	return (point);
}
